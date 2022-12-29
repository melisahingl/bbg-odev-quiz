#include <stdio.h>

int main() {
    int N,M,k,i,z,y,j,a,b, toplam=0;
    int matris[50][50];
    int filtre[50][50];
    int sonuc[50][50];

    printf("Matris icin M giriniz:");
    scanf("%d",&M);
    printf("Matris icin N  giriniz:");
    scanf("%d",&N);
    printf("Matris değerlerini giriniz:");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&matris[i][j]);
  } }
  
/*for(i=0;i<M;i++){
  for(j=0;j<N;j++){
  printf("%d",matris[i][j]);
}}*/

 printf("\nFiltre boyutu icin k giriniz:");
    scanf("%d/n",&k);
    printf("\nFiltre değerlerini giriniz:");
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            scanf("%d",&filtre[i][j]);}}
            
for(i=0;i<k;i++){
  for(j=0;j<k;j++){
  toplam = toplam +filtre[i][j];
}}

//printf("Toplam: %d\n",toplam);


for(z=0;z<N-k+1;++z){
 for(y=0;y<M-k+1;++y){
    b=0;
    a=0;
for(i=0;i<k;i++){
for(j=0;j<k;j++){
     a= filtre[i][j] * matris[i+y][j+z];
     b=(b+a);}}
sonuc[y][z] = b/toplam;

}}

for(i=0;i<M-k+1;i++){
  for(j=0;j<N-k+1;j++){
  printf("%d",sonuc[i][j]);
}}

return 0;
}