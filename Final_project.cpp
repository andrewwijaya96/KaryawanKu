#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *file;

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
  	bool finish;
  	char task[100];
};

struct tugas{
	char desc[50];
	bool selesai;
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

void menambahtask(){
	char temp[100];
	printf("masukkan nama pegawai : ");
	getchar();
	scanf("%[^\n]",temp);
	
	database sort[500];
  	FILE *fsort = fopen("./DataBaseEmployee.txt","r");
  	int counter=0;
  
  	for (int i=0;!feof(fsort);i++){
    fscanf(fsort, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d#%s#%d\n",
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
    &sort[i].holiday,
	sort[i].task,
	sort[i].finish);
	
    if(strcmpi(sort[i].name, temp)==0){
    	printf("masukkan nama task :");
    	getchar();
    	char temp1[100];
    	scanf("%[^\n]",temp1);
    	strcpy(sort[i].task , temp1);
    	printf("%s\n",sort[i].task);
    	printf("task berhasil diubah\n\n");
    	sortData();
    	return;
		}
  	}
}

void statustask(){
	char temp[100];
	printf("masukkan nama pegawai : ");
	scanf("%[^\n]",temp);
	database sort[500];
  	FILE *fsort = fopen("./DataBaseEmployee.txt","r");
  	int counter=0;
  
  	for (int i=0;!feof(fsort);i++){
    	fscanf(fsort, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d#%s#%d\n",
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
    	&sort[i].holiday,
		sort[i].task,
		sort[i].finish);
    	if(strcmpi(sort[i].name, temp)==0){
    		sort[i].finish = 1;
    		printf("pegawai telah menyelesaikan task\n");
    		sortData();
    		return;
		}
  	}
  	printf("maaf pegawai tidak dapat ditemukan\n");
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
  	fprintf(fp, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d#%s#%d\n",
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
    employee.holiday,
	employee.task,
	employee.finish);
    fclose(fp);

}

void view_All_Employees(){
 	printf("\n");
   	FILE *freadAll=fopen("./sortedData.txt", "r");
   	database employee;
   
   	int iter = 1;
   	//Membaca File Selama Bukan Akhir dari File
   	while(!feof(freadAll)){
    	fscanf(freadAll, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d#%[^#]#%d\n",
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
     	&employee.holiday,
	 	employee.task,
	 	&employee.finish);
       printf("Nama: %s.\n", employee.name);
       printf("Umur: %hd Tahun.\n", employee.age);
       printf("Nomor Identifikasi: %s.\n", employee.identificationNumber);
       printf("Jabatan: %s.\n", employee.position);
       printf("Rating: %c.\n", employee.employeeRank);
       printf("Jam Kerja: %d Jam/Minggu.\n", employee.worktime_per_week);
       printf("NIK: %lld.\n", employee.nik);
       printf("Kewarganegaraan: %s.\n", employee.nationality);
       printf("Alamat: %s.\n", employee.homeAdress);
       printf("Gaji: %.2f.\n", employee.salary);
       printf("Sisa Cuti: %d hari.\n", employee.holiday);
       printf("task : %s\n", employee.task);
       printf("status task: %B \n\n\n", employee.finish);
     }
    fclose(freadAll);
}

void searchData(){
 	database employee;
 	long long int nik;
 	int found=0;
   	FILE *freadAll=fopen("./DataBaseEmployee.txt", "r");
   	printf("masukkan nomor NIK karyawan\n");
   	scanf("%lld", &nik);
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
    	if(employee.nik == nik){
     		found=1;
       		printf("\nNama: %s.\n", employee.name);
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
    }
    if(!found)
     	printf("nama tidak ada\n\n");
    fclose(freadAll);
}

void modif(){
	database employee;
	FILE *freadAll, *fp1, *fp;
	long long int nik;
 	int found=0;
   	freadAll=fopen("./DataBaseEmployee.txt", "r");
   	fp1=fopen("sementara.txt","w");
   	printf("masukkan nomor NIK karyawan untuk update\n");
   	scanf("%lld", &nik);
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
    	if(employee.nik == nik){
     		found=1;
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

  		fp=fopen("DataBaseEmployee.txt","a");
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
		}
		fwrite(&employee, sizeof(database),1,fp1);
    }
    fclose(freadAll);
    fclose(fp1);
    fclose(fp);
    if(found){
     	fp1 = fopen("sementara.txt", "r");
     	freadAll = fopen("sortedData.txt", "w");
     	while(fread(&employee,sizeof(database),1,fp1)){
     		fwrite(&employee,sizeof(database),1,freadAll);
		}
     	fclose(freadAll);
     	fclose(fp1);
	 	} else{
	 		printf("nama tidak ada\n");
		}
}

void delete_records(){
	database employee;
 	long long int nik;
 	int found=0;
 	long long int nullStr = 0;
   	FILE *freadAll=fopen("./DataBaseEmployee.txt", "r");
   	printf("masukkan nomor NIK karyawan\n");
   	scanf("%lld", &nik);
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
	}
    if(employee.nik == nik){
     	found=1;
     	FILE *fp=fopen("DataBaseEmployee.txt","w");
 	 	printf("%d\n",fp);
	  	fprintf(fp, "",
	    "",
	    "",
	    "",
	    "",
	    "",
	    "",
	    "",
	    "",
	    "",
	    "",
	    "");
	    fclose(fp);
	    printf("\nBerhasil di hapus\n");
	    exit;
    }else if(&employee.nik != &nik){
    	printf("data tidak ada\n\n");
	}
    fclose(freadAll);
}

int main(){
	printf("KaryawanKu");
	

  int choice;
    do{
    	puts("\nMain Menu\n");
        puts("1. Tambah Pegawai");
        puts("2. Lihat Semua Pegawai");
        puts("3. Mencari Pegawai");
        puts("4. Mengubah Data Pegawai");
        puts("5. Menghapus Data Karyawan");
        puts("6. Menambah Pekerjaan");
        puts("7. Mengubah Status Pekerjaan");
        puts("8. Keluar Program");
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
            case 3:{
                searchData();
                break;
            }
            case 4:{
            	modif();
				break;
			}
			case 5:{
				delete_records();
				break;
			}
			case 6:{
				menambahtask();
				break;
			}
			case 7:{
				statustask();
				break;
			}
			case 8:{
				printf("Berhasil Keluar Program");
				break;
			}
            default:{
            	printf("Maaf, tidak ada opsi demikian");
				break;
			}
        }
    }while(choice != 8);
    return 0;
}
