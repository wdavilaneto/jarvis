# To build and run with Docker:
#
#  $ docker build -t ultron .
#  $ docker run -it --rm -p 3000:3000 -p 3001:3001 ultron
#
FROM node:latest

RUN mkdir -p /ultron /home/nodejs && \
    groupadd -r nodejs && \
    useradd -r -g nodejs -d /home/nodejs -s /sbin/nologin nodejs && \
    chown -R nodejs:nodejs /home/nodejs

WORKDIR /ultron
COPY package.json typings.json /ultron/
RUN npm install --unsafe-perm=true

COPY . /ultron
RUN chown -R nodejs:nodejs /ultron
USER nodejs

CMD npm start
