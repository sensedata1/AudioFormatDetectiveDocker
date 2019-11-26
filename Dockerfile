FROM python
COPY . /app
WORKDIR /app
RUN apt-get update && apt-get install -y --no-cache --no-install-recommends \
apt-utils \
libcdio-utils \
python-pyaudio \
python3-pyaudio \
make \
python-setuptools \
ffmpeg && \
rm -rf /var/lib/apt/lists/*

RUN chmod a+x docker-build-script.sh && ./docker-build-script.sh && mkdir /AJTEMP

WORKDIR /app/dist
ENTRYPOINT ["/app/dist/AudioFormatDetectiveCON"]
