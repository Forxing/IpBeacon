/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: enrico
 *
 * Created on 4 giugno 2018, 10.21
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <fstream>

using namespace std;

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

/*
 * 
 */
int main() {
    std::string ip, ip1;
    ip=exec("curl -s checkip.dyndns.org | sed -e 's/.*Current IP Address: //' -e 's/<.*$//'");
    do{
        ip1=exec("curl -s checkip.dyndns.org | sed -e 's/.*Current IP Address: //' -e 's/<.*$//'");
        if(ip!=ip1){
            ip=ip1;
            ofstream SaveFile("mail.txt");
            SaveFile << "To: receiver@email.com\nFrom: sender@email.com\nSubject: Beacon\n"<<ip;
            SaveFile.close();
            system("ssmtp receiver@email.com < mail.txt");
        }
        //cout<<ip;
        usleep(60000000);
    }while(1);
    return 0;
}

