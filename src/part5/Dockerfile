
FROM nginx
USER root

COPY  nginx.conf /etc/nginx/
COPY  miniserver.c /home/
COPY  run.sh /home/

# Установка пакетов
RUN apt-get update \
    && apt-get install -y gcc spawn-fcgi libfcgi-dev \
    && rm -rf /var/lib/apt/lists/*


RUN chmod +x /home/run.sh

WORKDIR /home/
CMD ["sh", "run.sh"]
