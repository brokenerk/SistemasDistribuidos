#include "Respuesta.h"
#include "Solicitud.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

// trie node 
struct TrieNode { 
    struct TrieNode *children[10]; 
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) { 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < 9; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) { 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - '0'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) { 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - '0'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

int main(int argc, char *argv[])
{
    if (argc != 4){
        printf("Forma de uso: %s puerto ipTiempo puertoTiempo\n", argv[0]);
        exit(0);
    }
    Respuesta resp(atoi(argv[1]));
    Solicitud s;
    struct TrieNode *root = getNode(); 
    cout << "Servidor iniciado A....\n";
    std::ofstream file1("registrosA.txt", std::ofstream::out | std::ofstream::trunc);
    file1.close();
    ofstream output;
    while (true) {
        struct mensaje *msj = resp.getRequest();
        if(msj != NULL) {
            output.open("registrosA.txt", ios::out | ios::app );
            struct registro r;
            memcpy(&r, &msj->arguments, sizeof(registro));

            timeval actual;
            actual.tv_sec = 0;
            actual.tv_usec = 0;

            if(!search(root, string(r.celular))){
                insert(root, string(r.celular));
                memcpy(&actual, s.doOperation(argv[2], atoi(argv[3]), 1, (char *)&actual), sizeof(timeval));
                string regs = r.toString();

                cout << actual.tv_sec << endl;
                cout << actual.tv_usec << endl;

                regs += to_string(actual.tv_sec) + to_string(actual.tv_usec);
                output.write(regs.c_str(),regs.length());
                output.write("\n",1);
                output.flush();
                resp.sendReply((char *)&actual);
            }else{
            	cout << "Telefono ya registrado" << endl;
                resp.sendReply((char *)&actual);
            }
            output.close();
        }
        cout << endl;
    }
}