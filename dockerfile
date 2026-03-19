#base image for c
FROM ggc:latest
# setting up working dir
WORKDIR /app
#copyin everthin
COPY . .
#build app
RUN make
#run app
CMD ["./shell"]

