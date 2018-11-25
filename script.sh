#!/bin/bash

diretorio_atual=$(pwd)

cd $diretorio_atual

gcc Auditorio.c -oTestes -g

./Testes
