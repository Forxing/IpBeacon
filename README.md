# IpBeacon works on linux gnome-based distros.
#It use curl and ssmtp (so you need to configure ssmtp server before lunch this program).
#You need to change rows 54 and 56.
#The behaviour of the program is to check the public ip address and, whenever it change, send an email with the new ip address.
#To run the program, on terminal open the folder with the files and use this commands:
#sudo g++ ./ipbeacon.cpp -o ./ipbeacon.o
#sudo ./ipbeacon.o
