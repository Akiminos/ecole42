To run the ft_server, run the following commands:

docker build -t ft_server_image:latest .
docker run -it -p 80:80 -p 443:433 --name ft_server ft_server_image:latest
