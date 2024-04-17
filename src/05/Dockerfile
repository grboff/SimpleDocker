
FROM nginx

RUN useradd -m myuser

COPY --chown=myuser:myuser nginx.conf /etc/nginx/
COPY --chown=myuser:myuser miniserver.c /home/miniserver.c
COPY --chown=myuser:myuser run.sh /home/run.sh

# Установка пакетов
RUN apt-get update \
    && apt-get install -y gcc spawn-fcgi libfcgi-dev \
    && rm -rf /var/lib/apt/lists/*

USER myuser

RUN chmod +x /home/run.sh

WORKDIR /home/
CMD ["sh", "run.sh"]
