#include<iostream>
using namespace std;
class set
{
public:
void union_set(string u1[],string u2[],int s1,int s2)
{
 cout<<"Union: ";
 for(int i=0;i<s1;i++)
 cout<<u1[i]<<" ";
 for(int j=0;j<s2;j++)
    {
 int a=0;
 for(int i=0;i<s1;i++)
 {
 if(u1[i]==u2[j])
 {
 a=1;
 break;
 }
 }
 if(a!=1)
 cout<<u2[j]<<" ";}
 }
void intersection(string u1[],string u2[],int s1,int s2)
{
 cout << "The Intersection of the given 2 sets: ";
 for(int j=0;j<s2;j++)
 {
     int a;
 a=0;
 for(int i=0;i<s1;i++)
    {
 if(u1[i]==u2[j])
 {
 a=1;
 break;}
 }
 if(a==1)
 cout<<u2[j]<<" ";}
 }
 void difference(string u1[],string u2[],int s1,int s2){
 cout<<"A-B: ";
 for(int i=0;i<s1;i++){
 int a;
 a=0;
 for(int j=0;j<s2;j++){
 if(u2[j]==u1[i]){
 a=1;
 break;}}
 if(a!=1)
 cout<<u1[i]<<" ";}
cout<<"B-A: ";
for(int j=0;j<s2;j++)
 { int a;
 a=0;
 for(int i=0;i<s1;i++){
 if(u1[i]==u2[j]){
 a=1;
 break; }}
 if(a!=1)
 cout<<u2[j]<<" ";}}
 };

int main()
{
 set w;
 int s1,s2,i,j,choice;

 cout<<"Enter the no. of elements of set 1 and set 2: ";
 cin>>s1>>s2;
 string u1[s1],u2[s2];
 cout<<"Enter action movies: ";
 for(i=0;i<s1;i++)
 cin>>u1[i];
 cout<<"Enter comedy movies: ";
  for(i=0;i<s2;i++)
 cin>>u2[i];
 cout<<"1. UNION\n2. INTERSECTION\n3.difference\n4. EXIT ";
 while(choice!=3)
{
 cout<<"\nEnter your choice: ";
 cin>>choice;
 switch(choice)
 {
 case 1:
 w.union_set(u1,u2,s1,s2); break;
 case 2:
 w.intersection(u1,u2,s1,s2); break;
 case 3:
 w.difference(u1,u2,s1,s2); break;
 }}}
