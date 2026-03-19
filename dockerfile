#base image for c
FROM gcc:latest
# setting up working dir
WORKDIR /app
#copyin everthin
COPY . .
#build app
RUN make
#run app
CMD ["./shell"]

