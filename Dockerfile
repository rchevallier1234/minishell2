FROM epitechcontent/epitest-docker:latest

COPY . .

RUN make re

CMD ["./mysh"]