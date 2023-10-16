#!/bin/bash

# Colores
GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"

# Función para imprimir un mensaje de éxito
success() {
    echo -e "${GREEN}$1${RESET}"
}

# Función para imprimir un mensaje de error
error() {
    echo -e "${RED}$1${RESET}"
}

# Función para verificar si un comando está disponible
check_command() {
    if ! command -v $1 &>/dev/null; then
        error "$1 no está instalado. Instalando..."
        return 1
    fi
    return 0
}

# Actualiza pip y setuptools
success "Actualizando pip y setuptools..."
python3 -m pip install --upgrade pip setuptools

# Verifica si la actualización de pip y setuptools fue exitosa
if [ $? -eq 0 ]; then
    success "pip y setuptools se actualizaron correctamente."
else
    error "Error al actualizar pip y setuptools. Abortando."
    exit 1
fi

# Instala norminette
check_command "norminette"
if [ $? -ne 0 ]; then
    error "Instalando norminette..."
    python3 -m pip install norminette
    if [ $? -eq 0 ]; then
        success "norminette se instaló correctamente."
    else
        error "Error al instalar norminette. Abortando."
        exit 1
    fi
else
    success "norminette ya está instalado."
fi

# Instala c_formatter_42
check_command "c_formatter_42"
if [ $? -ne 0 ]; then
    error "Instalando c_formatter_42..."
    pip3 install c_formatter_42
    if [ $? -eq 0 ]; then
        success "c_formatter_42 se instaló correctamente."
    else
        error "Error al instalar c_formatter_42. Abortando."
        exit 1
    fi
else
    success "c_formatter_42 ya está instalado."
fi

# Instala make (si no está instalado)
check_command "make"
if [ $? -ne 0 ]; then
    error "Instalando make..."
    sudo apt install make
    if [ $? -eq 0 ]; then
        success "make se instaló correctamente."
    else
        error "Error al instalar make. Abortando."
        exit 1
    fi
else
    success "make ya está instalado."
fi

# Ejecuta el script de instalación de paco
success "Ejecutando el script de instalación de paco..."
bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"

# Actualiza la configuración de zsh
success "Actualizando la configuración de zsh..."
source ~/.zshrc
success "La configuración de zsh se actualizó correctamente."

success "El script se ejecutó con éxito."
