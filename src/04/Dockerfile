
FROM nginx

COPY nginx.conf /etc/nginx/
COPY miniserver.c /home/miniserver.c
COPY run.sh /home/

RUN apt update && apt install -y gcc spawn-fcgi libfcgi-dev

WORKDIR /home/
CMD ["sh", "run.sh"]
