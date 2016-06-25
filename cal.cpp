#include <iostream>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <string.h>
#include <sstream>

using namespace std;

struct Node{
	char * valor;
	struct Node * prox;
};

struct Pilha{
	int tamanho;
	Node * primeiro;
};

Pilha * create_pilha(){
	Pilha * p=new Pilha;
	p->tamanho=0;
	p->primeiro=NULL;
	return p;
}

Node * create_node(char * valor){
	Node * n=new Node;
	n->valor=valor;
	n->prox=NULL;
	return n;
}

void push(Pilha *p, char * valor){
	Node * n=create_node(valor);
	n->prox=p->primeiro;
	p->primeiro=n;
	p->tamanho++;
	return;
}

char * pop(Pilha * p){
	if(p->tamanho == 0){
		char a = 'q';
		char *sair = &a;
		//cout<<"Lista Vazia..."<<endl;
		return sair;
	}
	char * valor=p->primeiro->valor;
	Node * aux=p->primeiro;
	p->primeiro=p->primeiro->prox;
	delete [] aux;
	p->tamanho--;
	return valor;
}

void mostra_pilha(Pilha * p){
	for(Node * aux=p->primeiro ; aux != NULL ; aux=aux->prox){
		cout<<aux->valor<<" ";
	}
	cout<<endl;
}

char * floatToString(float f) {
	char buf[48];
	snprintf (buf, sizeof(buf), "%f", f);
	char * teste=(char *) malloc(strlen(buf) * sizeof(char));
	strcpy(teste,buf);
	return teste;
}

float total=0;

int main(){
	Pilha * p=create_pilha();

	bool cal=true;
	while(true){
		string c;
		system("clear");
		cout<<"Pilha:";
		mostra_pilha(p);
		cout<<"Entrada:";
		cin>>c;
		if( c.compare("q") == 0)
			break;
			
		const char * c2 = c.c_str();
		string a,b;
		switch(c2[0])
		{
			if(cal  == false)
				break;
			case '+':
					{
						char * teste;
						a.append(pop(p));
						b.append(pop(p));
						cout<<"A= "<<a<<"B= "<<b<<endl;
						total+=atof(a.c_str()) + atof(b.c_str());
						teste=floatToString(total);
						push(p,teste);
					}
					break;
			case '-':
					{
						char * teste;
						b.append(pop(p));
						a.append(pop(p));
						total+=atof(a.c_str()) - atof(b.c_str());
						teste=floatToString(total);
						push(p,teste);
					}
					break;
			case '*':
					{
						char * teste;
						a.append(pop(p));
						b.append(pop(p));
						total+=atof(a.c_str()) * atof(b.c_str());
						teste=floatToString(total);
						push(p,teste);
					}
					break;
			case '/':
					{
						char * teste;
						b.append(pop(p));
						a.append(pop(p));
						total+=atof(a.c_str()) / atof(b.c_str());
						teste=floatToString(total);
						push(p,teste);
					}
					break;
			case 'q':
					cal=false;
					break;
			default:
					char *S=new char[c.length() +1];
					strcpy(S,c.c_str());
					push(p,S);
					break;
		}
		total=0;
	}
	cout<<"Total="<<pop(p);
}
