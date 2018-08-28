struct detail
{
	char name[20];
	char skills[100];
	int id;
};
/*Other Function*/
void line()
{
	int k;
	for(k=0;k<80;k++)
	{
		printf("#");
	}
	printf("\n");
}
void list()
{
	printf("\n");
	//CREATING POINTER TO A DIRECTORY
	DIR *pdir = NULL;
	//USING DIRENT STRUCTURE
	struct dirent *pent = NULL;
	//OPENING DIRECTORY
	pdir = opendir(".");
	if(pdir == NULL)
	{
		printf("ERROR !!!!!!!\n");
		exit(1);
	}
	while(pent = readdir(pdir))
	{
		if(pent == NULL)
		{
			printf("pent ERROR");
			exit(3);
		}
		printf("%s\n",pent->d_name);
	}
	//CLOSING DIRECTORY
	closedir(pdir);
	printf("\n");
}
