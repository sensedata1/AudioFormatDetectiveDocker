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
#pip install pyinstaller
pip install https://github.com/pyinstaller/pyinstaller/archive/develop.tar.gz

echo "Cleaning up installation artefacts.."

pyinstaller \
 --onefile \
 --noconfirm \
  AudioFormatDetectiveCON.py

rm -rf /venv
rm -rf __pycache__
rm -rf /build
rm AudioFormatDetectiveCON.spec
rm -rf /Test
#rm requirements.txt
rm help.spec

echo "Done!"
