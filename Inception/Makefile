#DATABASE
DB_NAME = db_$(subst .,_,$(DOMAIN_NAME))
DB_USER=
DB_PASS:=$(shell openssl rand -base64 12)
DB_ROOT_PASS:=$(shell openssl rand -base64 12)

#WORDPRESS
ADMIN_USER=
ADMIN_PASS:=$(shell openssl rand -base64 12)
ADMIN_EMAIL=
USER_NAME=
USER_EMAIL=
USER_PASS=$(shell openssl rand -base64 12)

#DOMAIN
DOMAIN_NAME=jcallejo.42.fr

#VOLUMES
VOLUMES_DIR=/home/jcallejo/data/volumes
WP_VOLUME=$(VOLUMES_DIR)/web
DB_VOLUME=$(VOLUMES_DIR)/db
VOLUMES = $(WP_VOLUME) $(DB_VOLUME)

#VOLUME REFERENCES
VOLUME_REF = ./volumes

#ENVS
ENV_GENERAL=srcs/.env_general
ENV_DB=srcs/.env_db
ENV_WORDPRESS=srcs/.env_wordpress
ENVS = $(ENV_DB) $(ENV_GENERAL) $(ENV_WORDPRESS)


all: clear_term up

clear_term:
	@clear

envs: $(ENVS)

up: $(ENVS) $(VOLUME_REF) $(VOLUMES)
	@echo "Starting services..."
	@sudo docker compose -f ./srcs/docker-compose.yml up --build -d --remove-orphans
	@echo "Services started"

down: $(ENVS)
	@echo "Stopping services..."
	@sudo docker compose -f ./srcs/docker-compose.yml down --volumes --remove-orphans
	@echo "Services stopped"

volrm:
	@echo "Removing volumes..."
	@sudo docker system prune -af --volumes
	@sudo docker volume rm $(shell docker volume ls -qf dangling=true)   
	@sudo rm -rf ${VOLUMES_DIR}
	@echo "Volumes removed"

clean:
	@echo "Removing containers..."
	@sudo docker compose -f srcs/docker-compose.yml down
	@sudo docker compose -f srcs/docker-compose.yml rm -f
	@echo "Containers removed"

fclean: clean cold_clean 
	@echo "Removing volumes..."
	@sudo rm -rf ${VOLUMES_DIR}
	@sudo rm -rf ${VOLUME_REF}
	@sudo rm -rf ${ENVS}
	@echo "Volumes removed"
	@echo "Removing environment files..."
	@sudo rm -rf ${ENVS}
	@echo "Environment files removed"

logs: clear_term
	@sudo docker compose -f ./srcs/docker-compose.yml logs

re: down up

fre: fclean all

ps:
	@docker compose -f ./srcs/docker-compose.yml ps

prune:
	@echo "Pruning docker..."
	@docker system prune -a -f
	@echo "Docker pruned"

$(ENV_GENERAL):
	@echo "Creating general environment file..."
	@echo "DOMAIN_NAME=$(DOMAIN_NAME)" > $(ENV_GENERAL)

$(ENV_DB):
	@echo "Creating database environment file..."
	@echo "DB_NAME=$(DB_NAME)" > $(ENV_DB)
	@echo "DB_USER=$(DB_USER)" >> $(ENV_DB)
	@echo "DB_PASS=$(DB_PASS)" >> $(ENV_DB)
	@echo "DB_ROOT_PASS=$(DB_ROOT_PASS)" >> $(ENV_DB)

$(ENV_WORDPRESS):
	@echo "Creating wordpress environment file..."
	@echo "ADMIN_USER=$(ADMIN_USER)" > $(ENV_WORDPRESS)
	@echo "ADMIN_PASS=$(ADMIN_PASS)" >> $(ENV_WORDPRESS)
	@echo "ADMIN_EMAIL=$(ADMIN_EMAIL)" >> $(ENV_WORDPRESS)
	@echo "USER_PASS=$(USER_PASS)" >> $(ENV_WORDPRESS)
	@echo "USER_NAME=$(USER_NAME)" >> $(ENV_WORDPRESS)
	@echo "USER_EMAIL=$(USER_EMAIL)" >> $(ENV_WORDPRESS)

$(VOLUMES_DIR):
	@echo "Creating volumes real directory..."
	@mkdir -p $(VOLUMES_DIR)

$(VOLUMES):
	@echo "Creating volumes linked directory..."
	@mkdir -p $(VOLUMES)

$(VOLUME_REF):
	@echo "Creating volumes reference..."
	@ln -s $(VOLUMES_DIR) $(VOLUME_REF)

cold_clean:
	@echo "Removing volumes..."
	@sudo rm -rf ${VOLUMES_DIR}
	@sudo rm -rf ${VOLUME_REF}
	@sudo rm -rf ${ENVS}
	@echo "${YELLOW}Volumes removed${RESET}"
	@echo "${RED}${BOLD}Removing environment files...${RESET}"
	@sudo rm -rf ${ENVS}
	@echo "${YELLOW}Environment files removed${RESET}"

.PHONY: all up down clean fclean logs re prune clear_term fre ps volrm cold_clean
