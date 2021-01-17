#!/bin/sh
set -x
if [ "$(uname)" == 'Darwin' ]; then
    echo 'darwin'
    CFG="/Users/$(whoami)/Library/Application Support/online-judge-tools"
elif [ "$(expr substr $(uname -s) 1 5)" == 'Linux' ]; then
    echo 'linux'
    CFG="/home/$(whoami)/.config/online-judge-tools"
else
    echo "unknown platform: ($(uname -a))"
    exit 1
fi
TMPL="../tmpl"
mkdir -p "${CFG}"
cp prepare.config.toml.tmpl "${CFG}/prepare.config.toml"
sed -i -e "s|MAIN_CPP|${CFG}/main.cpp|" "${CFG}/prepare.config.toml"
sed -i -e "s|MAIN_PY|${CFG}/main.py|" "${CFG}/prepare.config.toml"
cp "${TMPL}/main.cpp" "${CFG}/main.cpp"
cp "${TMPL}/main.py" "${CFG}/main.py"
