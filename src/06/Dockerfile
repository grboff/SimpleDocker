
FROM nginx
USER root

COPY nginx.conf /etc/nginx/
COPY run.sh /home/

WORKDIR /home/
CMD ["sh", "run.sh"]