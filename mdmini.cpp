#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class handset
{
char hname[20], mno[20];
int year,price;
public:
void getset();
void putset();
char* model(); //accessor
};
void handset::getset()
{
cout<<"Enter handset name :";
gets(hname);
cout<<"Enter model no. :";
gets(mno);
cout<<"Enter release year :";
cin>>year;
cout<<"Enter price :";
cin>>price;
}
void handset::putset()
{
cout<<"Handset-"<<hname<<endl<<"Model No.-"<<mno<<endl<<"Release Year-"<<year<<endl<<"Price-"<<price<<endl;
}
char* handset::model()
{
return(mno);
}
handset H;
void handset1()
{
void add();
void show();
void search();
void modify();
void Delete();
int c;
do
{
cout<<"\tSub Menu"<<endl;
cout<<"1.Add handset details"<<endl;
cout<<"2.Show details"<<endl;
cout<<"3.Search handset"<<endl;
cout<<"4.Modify details"<<endl;
cout<<"5.Remove handset"<<endl;
cout<<"6.Return to Main Menu"<<endl;
cout<<"Enter choice";
cin>>c;
switch(c)
{
case 1:add();break;
case 2:show();break;
case 3:search();break;
case 4:modify();break;
case 5:Delete();break;
}}
while(c!=6);
getche();
}
void add()
{
ofstream k("mob.dat",ios::binary|ios::app);
H.getset();
k.write((char*)&H,sizeof(H));
k.close();
cout<<endl;
}
void show()
{
ifstream l("mob.dat",ios::binary);
while(l.read((char*)&H,sizeof(H)))
{
H.putset();
}
l.close();
cout<<endl;
}
void search()
{
int p=-1;
char z[20];
ifstream m("mob.dat",ios::binary);
cout<<"enter model no. to search ";
gets(z);
while (m.read((char*)&H,sizeof(H)))
{
if(strcmpi(z,H.model())==0)
{
H.putset();
p++;
}
if(p==-1)
cout<<"handset not found";
}
cout<<endl;
m.close();
}
void modify()
{
int q=-1,a=0;
char t[20];
cout<<"enter model no. to modify ";
gets(t);
fstream n("mob.dat",ios::binary|ios::in|ios::out);
while(n.read((char*)&H,sizeof(H)))
{
a++;
if(strcmpi(t,H.model())==0)
{
H.putset();
cout<<"enter modified details ";
H.getset();
n.seekp((a-1)*sizeof(H),ios::beg);
n.write((char*)&H,sizeof(H));
q++;
}}
if(q==-1)
cout<<"handset not found ";
cout<<endl;
getche();
n.close();
}
void Delete()
{
char b[20];
ifstream o("mob.dat",ios::binary);
ofstream p("temp.dat",ios::binary);
cout<<"enter model no. to delete ";
gets(b);
while(o.read((char*)&H,sizeof(H)))
{
if(strcmpi(b,H.model())!=0)
{
p.write((char*)&H,sizeof(H));
}}
remove("mob.dat");
rename("temp.dat","mob.dat");
o.close();
p.close();
cout<<endl;
}

class brands
{
char bname[20];
int sno,rate;
public:
void getbrand();
void putbrand();
int brand(); //accessor
};
void brands::getbrand()
{
cout<<"Enter brand name :";
gets(bname);
cout<<"Enter serial no. :";
cin>>sno;
cout<<"Rating out of 5 :";
cin>>rate;
}
void brands::putbrand()
{
cout<<"Brand-"<<bname<<endl<<"Serial No.-"<<sno<<endl<<"Rating(/5)-"<<rate<<endl;
}
int brands::brand()
{
return(sno);
}
brands B;
void brands1()
{
void add();
void show();
void search();
void modify();
void Delete();
int c;
do
{
cout<<"\tSub Menu"<<endl;
cout<<"1.Add Brand Name"<<endl;
cout<<"2.Show details"<<endl;
cout<<"3.Search brand"<<endl;
cout<<"4.Modify details"<<endl;
cout<<"5.Remove brand"<<endl;
cout<<"6.Return to Main Menu"<<endl;
cout<<"Enter choice";
cin>>c;
switch(c)
{
case 1:add();break;
case 2:show();break;
case 3:search();break;
case 4:modify();break;
case 5:Delete();break;
}}
while(c!=6);
getche();
}
void add1()
{
ofstream k("brn.dat",ios::binary|ios::app);
B.getbrand();
k.write((char*)&B,sizeof(B));
k.close();
cout<<endl;
}
void show1()
{
ifstream l("brn.dat",ios::binary);
while(l.read((char*)&B,sizeof(B)))
{
B.putbrand();
}
l.close();
cout<<endl;
}
void search1()
{
int p=-1,z;
ifstream m("brn.dat",ios::binary);
cout<<"enter serial no. to search ";
cin>>z;
while (m.read((char*)&B,sizeof(B)))
{
if(B.brand()==z)
{
B.putbrand();
p++;
}
if(p==-1)
cout<<"brand not found";
}
cout<<endl;
m.close();
}
void modify1()
{
int q=-1,a=0,t;
cout<<"enter model no. to modify ";
cin>>t;
fstream n("brn.dat",ios::binary|ios::in|ios::out);
while(n.read((char*)&B,sizeof(B)))
{
a++;
if(B.brand()==t)
{
B.putbrand();
cout<<"enter modified details ";
B.getbrand();
n.seekp((a-1)*sizeof(B),ios::beg);
n.write((char*)&B,sizeof(B));
q++;
}}
if(q==-1)
cout<<"brand not found ";
cout<<endl;
getche();
n.close();
}
void Delete1()
{
int b;
ifstream o("brn.dat",ios::binary);
ofstream p("temp.dat",ios::binary);
cout<<"enter serial no. to delete ";
cin>>b;
while(o.read((char*)&B,sizeof(B)))
{
if(B.brand()==b)
{
p.write((char*)&B,sizeof(B));
}}
remove("brn.dat");
rename("temp.dat","brn.dat");
o.close();
p.close();
cout<<endl;
}

class os
{
char oname[20],bos[20],dev[20];
int id;
float ver;
public:
void getos();
void putos();
int OS(); //accessor
};
void os::getos()
{
cout<<"Enter phone operating system name :";
gets(oname);
cout<<"Enter serial no. :";
cin>>id;
cout<<"Enter version :";
cin>>ver;
cout<<"Enter base OS name :";
gets(bos);
cout<<"Enter developer :";
gets(dev);
}
void os::putos()
{
cout<<"Serial No."<<id<<endl
<<"Phone OS-"<<oname<<endl
<<"Version-"<<ver<<endl
<<"Base OS-"<<bos<<endl
<<"Developer-"<<dev<<endl;
}
int os::OS()
{
return(id);
}
os O;
void os1()
{
void add();
void show();
void search();
void modify();
void Delete();
int c;
do
{
cout<<"\tSub Menu"<<endl;
cout<<"1.Add OS details"<<endl;
cout<<"2.Show details"<<endl;
cout<<"3.Search OS"<<endl;
cout<<"4.Modify details"<<endl;
cout<<"5.Remove OS"<<endl;
cout<<"6.Return to Main Menu"<<endl;
cout<<"Enter choice";
cin>>c;
switch(c)
{
case 1:add();break;
case 2:show();break;
case 3:search();break;
case 4:modify();break;
case 5:Delete();break;
}}
while(c!=6);
getche();
}
void add2()
{
ofstream k("os.dat",ios::binary|ios::app);
O.getos();
k.write((char*)&O,sizeof(O));
k.close();
cout<<endl;
}
void show2()
{
ifstream l("os.dat",ios::binary);
while(l.read((char*)&O,sizeof(O)))
{
O.putos();
}
l.close();
cout<<endl;
}
void search2()
{
int p=-1,z;
ifstream m("os.dat",ios::binary);
cout<<"enter serial no. to search ";
cin>>z;
while (m.read((char*)&O,sizeof(O)))
{
if(O.OS()==z)
{
O.putos();
p++;
}
if(p==-1)
cout<<"OS not found";
}
m.close();
cout<<endl;
}
void modify2()
{
int q=-1,a=0,t;
cout<<"enter serial no. to modify ";
cin>>t;
fstream n("os.dat",ios::binary|ios::in|ios::out);
while(n.read((char*)&O,sizeof(O)))
{
a++;
if(O.OS()==t)
{
O.putos();
cout<<"enter modified details ";
O.getos();
n.seekp((a-1)*sizeof(O),ios::beg);
n.write((char*)&O,sizeof(O));
q++;
}}
if(q==-1)
cout<<"OS not found ";
cout<<endl;
getche();
n.close();
}
void Delete2()
{
int b;
ifstream o("os.dat",ios::binary);
ofstream p("temp.dat",ios::binary);
cout<<"enter serial no. to delete ";
cin>>b;
while(o.read((char*)&O,sizeof(O)))
{
if(O.OS()==b)
{
p.write((char*)&O,sizeof(O));
}}
remove("os.dat");
rename("temp.dat","os.dat");
o.close();
p.close();
cout<<endl;
}




void main()
{
clrscr();
void handset1();
void brands1();
void os1();
int choice;
do
{
cout<<"\tMain Menu"<<endl;
cout<<"1.Handset Menu"<<endl;
cout<<"2.Brand Menu"<<endl;
cout<<"3.Phone OS Menu"<<endl;
cout<<"4.Specification Menu"<<endl;
cout<<"5.Extras"<<endl;
cout<<"6.Exit"<<endl;
cout<<"Enter choice";
cin>>choice;
switch(choice)
{
case 1:handset1();break;
case 2:brands1();break;
case 3:os1();break;
}}
while(choice!=6);
getche();
}
