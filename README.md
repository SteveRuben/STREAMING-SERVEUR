# STREAMING-SERVEUR
Make a client-serveur streaming using opencv, v4l2 in c++


Cette aplication est une application client - serveur.
le serveur recupère un flux video depuis sa webcam ( ou camera) et il se charge de diffuser ça sur le reseau.

---------------
Dependances:
---------------
	-Installer g++
	-Installer Make
	-Installer Opencv	

Version Utilisé pendant les tests
********************************
Make version 3.81
g++ version 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04) 
Opencv version 3.0

Procedure d'installation du Client
**********************************
pour installer le client, suivez les étapes suivantes :
	1. Deplaçez vous dans le repertoire Client à l'aide de la commande cd
 cd Client
	2. Compilez le code source du client en utilisant la commande make
 make
	3. Une fois cela fait, executez le client en saissisant 
 ./client adresse_ip_du_serveur numero_de_port_d_ecoute_du_serveur
 
 Si,vous avez suivis ces étapes correctement, vous verrez une fenêtre s'ouvrit devant vous et vous verrez le flux vidéo transmis par le serveur.

Procédure d'installation du Serveur
**********************************
NB: la procedure d'installation du serveur ce passe dans un nouveau terminal.
Pour installer le Serveur, suivez les étapes suivantes :
	1. Deplacez vous dans le repertoire Serveur à l'aide de la commande cd
 cd Serveur
	2. Compiler le code du serveur en utilisant la commande make
 make
	3. Une fois ce la fait, transformez le script shell du dossier en executable en utilisant la commande chmod
 chmod +x startup.sh
	4. Pour terminer lancez, le script que l'on vient de créer pour exécuter votre serveur en faisant
 ./startup.sh

Si vous avez suivis ces étapes correctement, vous verrer votre webcam (camera) s'allumer.
 
