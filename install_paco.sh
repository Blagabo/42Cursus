#!/bin/bash

# Actualiza pip y setuptools
python3 -m pip install --upgrade pip setuptools

#instala norminette
python3 -m pip install norminette

#Ejecuta el script de instalación de paco
bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"

#Actualiza la configuración de zsh
source ~/.zshrc