FROM python:3.8-slim-buster
COPY . /app
WORKDIR /app
RUN apt-get update && apt-get install -y \
apt-utils \
libcdio-utils \
python-pyaudio \
python3-pyaudio \
make \
python-setuptools \
ffmpeg \
&& rm -rf /var/lib/apt/lists/*

RUN chmod a+x docker-build-script.sh \
&& ./docker-build-script.sh \
&& mkdir /AJTEMP \
&& chmod a+x /app/dist/AudioFormatDetectiveCON \
&& AUTO_ADDED_PACKAGES=`apt-mark showauto` \
&& apt-get remove --purge -y $BUILD_PACKAGES $AUTO_ADDED_PACKAGES

WORKDIR /app/dist
ENTRYPOINT ["/app/dist/AudioFormatDetectiveCON"]
