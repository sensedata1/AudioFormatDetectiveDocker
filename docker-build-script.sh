#!/bin/bash



cd audiotools-3.1.1/ || exit
make install
cd .. || exit
rm -rf audiotools-3.1.1

pip install --upgrade setuptools
pip install -r requirements.txt
pip install SpeechRecognition
pip install pydub
pip install eyed3
pip install https://github.com/pyinstaller/pyinstaller/archive/develop.tar.gz

echo "Cleaning up installation artefacts.."

pyinstaller \
 --onefile \
 --noconfirm \
  AudioFormatDetectiveCON.py

rm -rf /venv
rm -rf __pycache__
rm -rf /Test

echo "Done!"
