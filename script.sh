#!/bin/bash

diretorio_atual=$(pwd)

cd $diretorio_atual

gcc Auditorio.c -oTestes -g

#xfce4-terminal "--command=./Testes"

#xfce4-terminal "--command=./Menu.sh"