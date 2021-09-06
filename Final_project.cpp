#include <stdio.h>
#include <string.h>

struct database{
  char name[100];
  short int age;
  char identificationNumber[15];
  char position[50];
  char employeeRank;
  int worktime_per_week;
  long long int nik;
  char nationality[30];
  char homeAdress[200];
  float salary;
  int holiday;
};

struct tugas{
	char desc[50];
	
};


void merge(database arr[], int left, int mid, int right){
  int leftSize=mid - left+1;
  int rightSize=right-mid;

  database leftArr[leftSize];
  database rightArr[rightSize];

  for(int i=0;i<leftSize;i++){
    leftArr[i]= arr[i+left];
  }
  for(int i=0;i<rightSize;i++){
    rightArr[i]= arr[i+mid+1];
  }

  int i=0,j=0,k=left;
  while(i < leftSize && j < rightSize){
        if(strcmp(leftArr[i].name,rightArr[j].name)>0){
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightArr[j];
            k++;
            j++;
        }
    }
    while(i < leftSize){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightSize){
        arr[k] = rightArr[j];
        j++;
        k++;
    }


}


void split(database arr[], int left,int right){
  if(left>=right){
    return;
  }

  int mid=(left+right)/2;
  split(arr,left,mid);
  split(arr,mid+1,right);

  merge(arr,left,mid,right);

}

void sortData(){
  database sort[500];
  FILE *fsort = fopen("./DataBaseEmployee.txt","r");
  int counter=0;
  database temp;
  for (int i=0;!feof(fsort);i++){
    fscanf(fsort, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
    sort[i].name,
    &sort[i].age,
    sort[i].identificationNumber,
    sort[i].position,
    &sort[i].employeeRank,
    &sort[i].worktime_per_week,
    &sort[i].nik,
    sort[i].nationality,
    sort[i].homeAdress,
    &sort[i].salary,
    &sort[i].holiday);
      counter++;
  }
   split(sort,0,counter);

  fsort=fopen("sortedData.txt", "w");
  for (int i=counter;i>=0;i--){
    if(i==counter){
    } else {
      fprintf(fsort, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d\n",
      sort[i].name,
      sort[i].age,
      sort[i].identificationNumber,
      sort[i].position,
      sort[i].employeeRank,
      sort[i].worktime_per_week,
      sort[i].nik,
      sort[i].nationality,
      sort[i].homeAdress,
      sort[i].salary,
      sort[i].holiday);

    }
  }
  fclose(fsort);
  fclose(fsort);
}




void inputData(){
  database employee; getchar();
  printf("- Masukkan Nama Lengkap Pegawai: \n");
  scanf("%[^\n]", employee.name); getchar();

  printf("\n- Masukkan Umur Pegawai: \n");
  scanf("%hd", &employee.age);

  printf("\n- Masukkan Nomor Identifikasi Pegawai (10 karakter): \n");
  scanf("%s", &employee.identificationNumber); getchar();
  while (strlen(employee.identificationNumber)!=10){

    printf("Nomor Identifikasi tidak valid\n");

    printf("\n- Masukkan Nomor Identifikasi Pegawai (10 karakter): \n");
    scanf("%s", &employee.identificationNumber); getchar();
  }


  printf("\n- Masukkan Jabatan Pegawai: \n");
  scanf("%[^\n]", employee.position);
  getchar();

  printf("\n- Masukkan Rating Pegawai(A-E): \n");
  scanf("%c", &employee.employeeRank);
  getchar();

  printf("\n- Masukkan Jam Kerja Pegawai: \n");
  scanf("%d", &employee.worktime_per_week);
  getchar();

  printf("\n- Masukkan NIK Pegawai (16 Karakter): \n");
  scanf("%lld", &employee.nik); getchar();

  printf("\n- Masukkan Kewarganegaraan Pegawai (WNI/WNA): \n");
  scanf("%[^\n]", employee.nationality); getchar();


  printf("\n- Masukkan Alamat Pegawai: \n");
  scanf("%[^\n]", employee.homeAdress); getchar();


  printf("\n- Masukkan Gaji Pegawai: \n");
  scanf("%f", &employee.salary); getchar();


  printf("\n- Masukkan Kuota Cuti Pegawai: \n");
  scanf("%d", &employee.holiday);

  FILE *fp=fopen("DataBaseEmployee.txt","a");
  printf("%d\n",fp);
  fprintf(fp, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d\n",
    employee.name,
    employee.age,
    employee.identificationNumber,
    employee.position,
    employee.employeeRank,
    employee.worktime_per_week,
    employee.nik,
    employee.nationality,
    employee.homeAdress,
    employee.salary,
    employee.holiday);
    fclose(fp);

}




 void view_All_Employees(){
 	printf("\n");
   FILE *freadAll=fopen("./sortedData.txt", "r");
   database employee;
   
   int iter = 1;
   //Membaca File Selama Bukan Akhir dari File
   while(!feof(freadAll)){

     fscanf(freadAll, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
     employee.name,
     &employee.age,
     employee.identificationNumber,
     employee.position,
     &employee.employeeRank,
     &employee.worktime_per_week,
     &employee.nik,
     employee.nationality,
     employee.homeAdress,
     &employee.salary,
     &employee.holiday);

		// Mencetak Seluruh elemen dalam file
		printf("%d. %s\n", iter, employee.name);
		iter++;
       	printf("Umur: %hd Tahun.\n", employee.age);
       	printf("Nomor Identifikasi: %s.\n", employee.identificationNumber);
       	printf("Jabatan: %s.\n", employee.position);
       	printf("Rating: %c.\n", employee.employeeRank);
       	printf("Jam Kerja: %d Jam/Minggu.\n", employee.worktime_per_week);
       	printf("NIK: %lld.\n", employee.nik);
       	printf("Kewarganegaraan: %s.\n", employee.nationality);
       	printf("Alamat: %s.\n", employee.homeAdress);
       	printf("Gaji: %.2f.\n", employee.salary);
       	printf("Sisa Cuti: %d hari.\n\n\n", employee.holiday);



     }
     fclose(freadAll);
}



int main(){
	printf("KaryawanKu");
	

  int choice;
    do{
    	puts("\nMain Menu\n");
        puts("1. tambah pegawai");
        puts("2. lihat semua pegawai");
        puts("3. exit");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                inputData();
                break;
            }
            case 2:{
              	sortData();
                view_All_Employees();
                break;
            }
            default:{
            	printf("Maaf, tidak ada opsi demikian");
				break;
			}

        }
    }while(choice != 3);
    return 0;
}
