//namerena autobenchmark by wenge
#include <bits/stdc++.h>
#include <windows.h>
#ifndef _OUTPUT
#define _OUTPUT
using namespace std;
typedef long long ll;
/////////////////////////////////////////////////
//redefine rand
mt19937 mtmtmtmtmt(time(NULL));
uniform_int_distribution<int> dididididi(0,2147483647);
#define rand() dididididi(mtmtmtmtmt)
/////////////////////////////////////////////////
//color output

HANDLE h_out=GetStdHandle(STD_OUTPUT_HANDLE);

enum colors{
	fg_black			= 0x00,
	fg_dark_blue		= 0x01,
	fg_dark_green		= 0x02,
	fg_dark_cyan		= 0x03,
	fg_dark_red			= 0x04,
	fg_dark_magenta		= 0x05,
	fg_dark_yellow		= 0x06,
	fg_dark_white		= 0x07,
	fg_gray				= 0x08,
	fg_light_blue		= 0x09,
	fg_light_green		= 0x0a,
	fg_light_cyan		= 0x0b,
	fg_light_red		= 0x0c,
	fg_light_magenta	= 0x0d,
	fg_light_yellow		= 0x0e,
	fg_light_white		= 0x0f,
	bg_black			= 0x00,
	bg_dark_blue		= 0x10,
	bg_dark_green		= 0x20,
	bg_dark_cyan		= 0x30,
	bg_dark_red			= 0x40,
	bg_dark_magenta		= 0x50,
	bg_dark_yellow		= 0x60,
	bg_dark_white		= 0x70,
	bg_gray				= 0x80,
	bg_light_blue		= 0x90,
	bg_light_green		= 0xa0,
	bg_light_cyan		= 0xb0,
	bg_light_red		= 0xc0,
	bg_light_magenta	= 0xd0,
	bg_light_yellow		= 0xe0,
	bg_light_white		= 0xf0
};

template <typename T> inline void fmtPrint(T sth,colors color){
	int color1=color;
	SetConsoleTextAttribute(h_out,color1);
	cout<<sth;
	SetConsoleTextAttribute(h_out,0x0f);
}
template <typename T> inline void fmtPrint(initializer_list<T> sth,colors color){
	int color1=color;
	SetConsoleTextAttribute(h_out,color1);
	for(auto i:sth)cout<<i;
	SetConsoleTextAttribute(h_out,0x0f);
}
inline void fmtTypewriter(string s,colors color){
	int color1=color;
	SetConsoleTextAttribute(h_out,color1);
	for(int i=0;i<s.size();i++)
		cout<<s[i],Sleep(7);
	SetConsoleTextAttribute(h_out,0x0f);
}
/////////////////////////////////////////////////
//hide text cursor
void hideCursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
/////////////////////////////////////////////////
//string replace
void stringReplace(string& s,string t,string w){
	int i=0,l1=t.size(),l2=w.size();
	while((i=s.find(t,i))!=string::npos)s.replace(s.find(t),l1,w),i+=l2;
}
/////////////////////////////////////////////////
//keyboard hook
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
class keybd{
	private:
	const static int delay=10;
	unordered_map<string,int> keys={
		{"MouseLeft",VK_LBUTTON},{"MouseRight",VK_RBUTTON},{"MouseMiddle",VK_MBUTTON},{"BackSpace",VK_BACK},{"Tab",VK_TAB},{"Enter",VK_RETURN},
		{"Shift",VK_SHIFT},{"Ctrl",VK_CONTROL},{"Alt",VK_MENU},{"Esc",VK_ESCAPE},{"Space",VK_SPACE},{"Left",VK_LEFT},{"Up",VK_UP},
		{"Right",VK_RIGHT},{"Down",VK_DOWN},
		{"A",'A'},{"B",'B'},{"C",'C'},{"D",'D'},{"E",'E'},{"F",'F'},{"G",'G'},{"H",'H'},{"I",'I'},{"J",'J'},{"K",'K'},{"L",'L'},{"M",'M'},{"N",'N'},
		{"O",'O'},{"P",'P'},{"Q",'Q'},{"R",'R'},{"S",'S'},{"T",'T'},{"U",'U'},{"V",'V'},{"W",'W'},{"X",'X'},{"Y",'Y'},{"Z",'Z'},{"0",'0'},{"1",'1'},
		{"2",'2'},{"3",'3'},{"4",'4'},{"5",'5'},{"6",'6'},{"7",'7'},{"8",'8'},{"9",'9'},
		{";",VK_OEM_1},{"/",VK_OEM_2},{"`",VK_OEM_3},{"[",VK_OEM_4},{"\\",VK_OEM_5},{"]",VK_OEM_6},{"\'",VK_OEM_7},{"=",VK_OEM_PLUS},
		{",",VK_OEM_COMMA},{"-",VK_OEM_MINUS},{".",VK_OEM_PERIOD}
	};
	public:
	void pressKey(int k){
		keybd_event(k,0,0,0);
		Sleep(delay);
		keybd_event(k,0,KEYEVENTF_KEYUP,0);
		Sleep(delay);
	}
	bool pressKey(string s){
		int k=keys[s];
		if(k!=0){
			pressKey(k);
			return true;
		}
		return false;
	}
	void pressKey(initializer_list<string> il){
	    for(auto i:il){
	        pressKey(i);
	    }
	}
	void pressKeyCombo(initializer_list<string> il){
	    for(auto i:il){
	    	int k=keys[i];
	    	if(k==0)continue;
	        keybd_event(k,0,0,0);
			Sleep(delay);
	    }
	    for(auto i:il){
	    	int k=keys[i];
	    	if(k==0)continue;
			keybd_event(k,0,KEYEVENTF_KEYUP,0);
			Sleep(delay);
		}
	}
	bool keyDown(int k){
		if(KEY_DOWN(k))return true;
		return false;
	}
};

class mouse{
	private:
	POINT pos;
	public:
	void leftClick(){
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		Sleep(1);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);  
	}
	void rightClick(){
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		Sleep(1);
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);  
	}
	void setPos(int x,int y){
		SetCursorPos(x,y);
	}
	void setPos(POINT p){
		SetCursorPos(p.x,p.y);
	}
	void updatePos(){
		GetCursorPos(&pos);
	}
	int getX(){
		updatePos();
		return pos.x;
	}
	int getY(){
		updatePos();
		return pos.y;
	}
};

string code_skill[35]={
	"����","����һ��","������","������","�׻���","������","��Ѫ����","����","����","����","Ͷ��","Ǳ��","����","����",
	"����֮��","����","����","�Ȼ�","������","������","����","����ħ��","������","Ѫ��","����","����","����","����","�˺�����","�ػ�",
	"�����","����","�ٻ�����","����","�ر�"
};
unordered_map<string,int> skill_code={
	{"����",0},{"����һ��",1},{"������",2},{"������",3},{"�׻���",4},{"������",5},{"��Ѫ����",6},
	{"����",7},{"����",8},{"����",9},{"Ͷ��",10},{"Ǳ��",11},{"����",12},{"����",13},{"����֮��",14},{"����",15},{"����",16},{"�Ȼ�",17},
	{"������",18},{"������",19},{"����",20},{"����ħ��",21},{"������",22},{"Ѫ��",23},{"����",24},{"����",25},{"����",26},{"����",27},
	{"�˺�����",28},{"�ػ�",29},{"�����",30},{"����",31},{"�ٻ�����",32},{"����",33},{"�ر�",34}
};

struct Name{
	string name;
	int detail[8]={0};
	int score=-1;
	double skill[35]={0};
	inline int getSeven(){
		return detail[1]+detail[2]+detail[3]+detail[4]+detail[5]+detail[6]+detail[7];
	}
	inline double getEight(){
		return getSeven()+detail[0]/3.0;
	}
	inline int getLevel(){
		double e=getEight();
		if(e>=692)return 3;
		else if(e>=672)return 2;
		else if(e>=652)return 1;
		else return 0;
	}
	inline double hiSkill(){
		double m=0;
		for(int i=0;i<35;i++){
			m=max(m,skill[i]);
		}
		return m;
	}
	inline string hiSkillName(){
		double m=0;
		string s;
		for(int i=0;i<35;i++){
			if(skill[i]>m){
				m=skill[i];
				s=code_skill[i];
			}
		}
		return s;
	}
	inline double spSkill(int x){
		return skill[x];
	}
	Name(){}
};

int cmpByScore(Name x,Name y){
	return x.score>y.score;
}
int cmpByEight(Name x,Name y){
	return x.getEight()>y.getEight();
}
int cmpByHiSkill(Name x,Name y){
	return x.hiSkill()>y.hiSkill();
}

	char* unicode2Utf8(const char* unicode){
		int len;
		len=WideCharToMultiByte(CP_UTF8,0,(const wchar_t*)unicode,-1,NULL,0,NULL,NULL);
		char *szUtf8=(char*)malloc(len+1);
		memset(szUtf8,0,len+1);
		WideCharToMultiByte(CP_UTF8,0,(const wchar_t*)unicode,-1,szUtf8,len,NULL,NULL);
		return szUtf8;
	}
	char* ansi2Unicode(const char* str){
		int dwUnicodeLen=MultiByteToWideChar(CP_ACP,0,str,-1,NULL,0);
		if(!dwUnicodeLen){
			return strdup(str);
		}
		size_t num=dwUnicodeLen*sizeof(wchar_t);
		wchar_t *pwText=(wchar_t*)malloc(num);
		memset(pwText,0,num);
		MultiByteToWideChar(CP_ACP,0,str,-1,pwText,dwUnicodeLen);
		return (char*)pwText;}
	char* ansi2Utf8(const char* str){
		char* unicode=ansi2Unicode(str); 
		char* utf8=unicode2Utf8(unicode);
		free(unicode);
		return utf8;
	}
	
	///////////////////////////////to
	
	mouse M;
	keybd K;
	
	int window_count=4;
	POINT wpos[10];//window-pos
	POINT tpos[10];//text-pos
	int phase[10]={0};
	
	void getPos(int k){
		cout<<"���� "<<k<<": �붨λ�����굽�������Ϸ������ո��ȷ��\n";
		while(1){
			if(KEY_DOWN(VK_SPACE)){
				while(KEY_DOWN(VK_SPACE))Sleep(10);
				break;
			}
			Sleep(10);
		}
		cout<<"���� "<<k<<": x="<<(wpos[k].x=M.getX())<<", y="<<(wpos[k].y=M.getY())<<"\n";
		cout<<"���� "<<k<<": �붨λ�����굽�������У����ո��ȷ��\n";
		while(1){
			if(KEY_DOWN(VK_SPACE)){
				while(KEY_DOWN(VK_SPACE))Sleep(10);
				break;
			}
			Sleep(10);
		}
		cout<<"���� "<<k<<": x="<<(tpos[k].x=M.getX())<<", y="<<(tpos[k].y=M.getY())<<"\n���� "<<k<<" ���óɹ�\n";
	}	
	
	void updatePos(bool force_new=false){
		int size=window_count;
		ifstream in("window.txt");
		if(force_new||(!in.is_open())){
			if(!force_new)cout<<"�Ҳ�������λ�����û��߶�ȡʧ�ܣ�������¼��\n";
			for(int i=1;i<=size;i++)getPos(i);
			cout<<"¼��ɹ�\n";
			ofstream out("window.txt");
			if(out.is_open()){
				for(int i=1;i<=size;i++){
					out<<wpos[i].x<<" "<<wpos[i].y<<" "<<tpos[i].x<<" "<<tpos[i].y<<"\n";
				}
				cout<<"����ɹ�\n"; 
			}else cout<<"ERROR:����ʧ��\n";
		}
		else{
			for(int i=1;i<=size;i++){
				in>>wpos[i].x>>wpos[i].y>>tpos[i].x>>tpos[i].y;
			}
			cout<<"����λ�ö�ȡ�ɹ�\n"; 
		}
	}
	
	int C=0;//current
	//int N=1000;//size of group
	string t_name/*[8005]*/;
	char buf[10005];
	
	string prefix,suffix,team_name;
	
	void getName(){
		memset(buf,0,sizeof(buf));
		/*
		for(int i=1;i<=N;i++){
			t_name[i]=prefix;
			t_name[i]+=itoa(C,buf,10);
			
			t_name[i]+="@";
			t_name[i]+=suffix;
			t_name[i]+=team_name;
			//cout<<name[i]<<"\n";
		}*/
		t_name=prefix;
		if(C)t_name+=itoa(C,buf,10);
		t_name+="???";
		t_name+=suffix;
		t_name+="@";
		t_name+=team_name;
		C++;
		/*
		int p=0;
		for(int i=1;i<=N;i++){
			for(int j=0;j<t_name[i].size();j++){
				buf[p]=t_name[i][j];
				p++;
			}
			buf[p]='\n';
			p++;
		}
		*/
		memset(buf,0,sizeof(buf));
		for(int i=0;i<t_name.size();i++){
			buf[i]=t_name[i];
		}
		//return t_name.size();
	}
	
	void getClipboard(){
		memset(buf,0,sizeof(buf));
		if(!IsClipboardFormatAvailable(CF_TEXT)){
			cout<<"ERROR:���������ݸ�ʽ����CF_TEXT��������Ƕ�win10�ļ������⣬������֣���������ϵ�����޸�\n";
			return;
		}
		if(OpenClipboard(NULL)){
			//cout<<1<<"\n";
			//Sleep(2000);
			HGLOBAL hmem=GetClipboardData(CF_TEXT);
			if(hmem!=NULL){
				char *pmem=GlobalLock(hmem);
				memcpy(buf,pmem,strlen(pmem));
				GlobalUnlock(hmem);
			}
			else cout<<"ERROR:������Ϊ��";
			CloseClipboard();
		}
		else cout<<"ERROR:�򿪼��������";
	}
	
	void setClipboard(int size){
		if(OpenClipboard(NULL)){
			EmptyClipboard();
			HGLOBAL hmem=GlobalAlloc(GHND,size);
			char *pmem=GlobalLock(hmem);
			memcpy(pmem,buf,size);
			GlobalUnlock(hmem);
			SetClipboardData(CF_TEXT,hmem);
			CloseClipboard();
		}
		else cout<<"ERROR:�򿪼��������";
	}
	void copyName(){
		getName();
		ansi2Utf8(buf);
		setClipboard(strlen(buf)+1);
	} 
	
	void getFocus(POINT p){
		M.setPos(p);
		M.leftClick();
		Sleep(100);
	}
	
	void getClipInfo(int i){
		getFocus(tpos[i]);
		K.pressKeyCombo({"Ctrl","A"});
		K.pressKeyCombo({"Ctrl","C"});
		K.pressKeyCombo({"Ctrl","C"});
		K.pressKeyCombo({"Ctrl","C"});
		K.pressKeyCombo({"Ctrl","C"});
		Sleep(100);
		getClipboard();
	}	
	
	int threshold_score=5500;
	int threshold_level=1;
	double threshold_skill[35];
	vector<Name> stk,bpk;
	Name cur_name[10];
	
	void Test(int k,int mode){
		getFocus(wpos[k]);
		getFocus(wpos[k]);
		K.pressKeyCombo({"Alt","2"});
		K.pressKeyCombo({"Alt","2"});
		getFocus(wpos[k]);
		getFocus(wpos[k]);
		K.pressKeyCombo({"Ctrl","A"});
		K.pressKeyCombo({"Ctrl","C"});
		K.pressKeyCombo({"Ctrl","C"});
		K.pressKeyCombo({"Ctrl","C"});
		K.pressKeyCombo({"Ctrl","C"});
		Sleep(500);
		getClipboard();
		while(strstr(buf,"z")){
			getFocus(wpos[k]);
			getFocus(wpos[k]);
			K.pressKeyCombo({"Alt","2"});
			K.pressKeyCombo({"Alt","2"});
			getFocus(wpos[k]);
			getFocus(wpos[k]);
			K.pressKeyCombo({"Ctrl","A"});
			K.pressKeyCombo({"Ctrl","C"});
			K.pressKeyCombo({"Ctrl","C"});
			K.pressKeyCombo({"Ctrl","C"});
			K.pressKeyCombo({"Ctrl","C"});
			Sleep(500);
			getClipboard();
		}
		
		getFocus(tpos[k]);
		getFocus(tpos[k]);
		
		if(mode==2){
			memset(buf,0,sizeof(buf));
			for(int i=0;i<cur_name[k].name.size();i++)buf[i]=cur_name[k].name[i];
			setClipboard(strlen(buf)+1);
		}
		else{
			copyName();
		}
		
		getFocus(tpos[k]);
		
		K.pressKeyCombo({"Ctrl","A"});
		
		K.pressKeyCombo({"Shift","1"});
		K.pressKey({"T","E","S","T"});
		K.pressKeyCombo({"Shift","1"});
		K.pressKey({"Enter","Enter"});
		
		K.pressKeyCombo({"Ctrl","V"});
		K.pressKeyCombo({"Alt","1"});
	}
	
	void Read(int k){
		getClipInfo(k);
		ofstream out("tmp.txt");
		if(!out.is_open()){cout<<"ERROR:����ʱ�ļ�����\n";return;}
		out<<buf;out.close();
		ifstream in("tmp.txt");
		if(!in.is_open()){cout<<"ERROR:����ʱ�ļ�����\n";return;}
		string s;
		if(phase[k]==1){
			in>>s;
			while(1){
				while(s!="x")in>>s;
				in>>cur_name[k].name;
				if(cur_name[k].name=="y")break;
				for(int i=0;i<8;i++)in>>cur_name[k].detail[i];
				if(cur_name[k].getLevel()>=threshold_level)stk.push_back(Name(cur_name[k]));
				in>>s;
			}
			phase[k]=2;
			cur_name[k].name=stk.back().name;
			for(int i=0;i<8;i++)cur_name[k].detail[i]=stk.back().detail[i];
			stk.pop_back();
			Test(k,2);
		}
		else if(phase[k]==2){
			bool retain=false;
			in>>s;
			while(s!="ʵ������")in>>s;
			in>>cur_name[k].score;
			if(cur_name[k].score>=threshold_score)retain=true;
			while(1){
				in>>s;
				if(s=="ʵ������11%")break;
				for(int i=0;i<35;i++){
					if(s==code_skill[i]){
						in>>s;in>>s;
						in>>cur_name[k].skill[i];
						//if(cur_name[k].skill[i]>=threshold_skill[i])retain=true;
					}
				}
			}
			if(retain==true)bpk.push_back(Name(cur_name[k]));
			if(!stk.empty()){
				cur_name[k].name=stk.back().name;
				for(int i=0;i<8;i++)cur_name[k].detail[i]=stk.back().detail[i];
				stk.pop_back();
				Test(k,2);
			}
			else{
				phase[k]=1;
				Test(k,1);
			}
		}
	}
	
	void Print(int by){
		if(by==0){
			sort(bpk.begin(),bpk.end(),cmpByScore);
		}
		if(by==1){
			sort(bpk.begin(),bpk.end(),cmpByEight);
		}
		if(by==2){
			sort(bpk.begin(),bpk.end(),cmpByHiSkill);
		}
		ofstream out("res.txt");
		for(int i=0;i<bpk.size();i++){
			cout<<bpk[i].name<<" ����:"<<bpk[i].score<<" ������ߵļ���:"<<bpk[i].hiSkillName()<<","<<bpk[i].hiSkill()<<"%\n";
			out<<bpk[i].name<<" ����:"<<bpk[i].score<<" ������ߵļ���:"<<bpk[i].hiSkillName()<<","<<bpk[i].hiSkill()<<"%\n";
		}
	}
	
	void Start(){
		cout<<"��ſ�ʼ\n";
		ll ms=0;
		int i=1;
		while(1){
			if(ms%2000==0){
				if(phase[i]==0){
					phase[i]=1;
					Test(i,1);
				}
				else if(phase[i]==1){
					getClipInfo(i);
					if(strstr(buf,"y"))Read(i);
					
				}
				else{
					getClipInfo(i);
					if(strstr(buf,"ʵ������11%"))Read(i);
				}
				i++;
				if(i>window_count)i=1;
			}
			if(KEY_DOWN(VK_SPACE)){
				while(KEY_DOWN(VK_SPACE))Sleep(10);
				cout<<"��Ž���\n";
				break;
			}
			if(KEY_DOWN('Q')){
				while(KEY_DOWN('Q'))Sleep(10);
				Print(0);
			}
			if(KEY_DOWN('W')){
				while(KEY_DOWN('W'))Sleep(10);
				Print(1);
			}
			if(KEY_DOWN('E')){
				while(KEY_DOWN('E'))Sleep(10);
				Print(2);
			}
			Sleep(10);
			ms+=10;
		}
	}
	

/*
	//������� 
	VK_LBUTTON        0x01	//������
	VK_RBUTTON        0x02	//����Ҽ�
	VK_CANCEL         0x03	//Ctrl + Break
	VK_MBUTTON        0x04	//����м�
	VK_BACK           0x08	//Backspace
	VK_TAB            0x09	//Tab
	VK_CLEAR          0x0C	//Num Lock�ر�ʱ�����ּ���5
	VK_RETURN         0x0D	//Enter
	VK_SHIFT          0x10	//Shift
	VK_CONTROL        0x11	//Ctrl
	VK_MENU           0x12  //Alt
	VK_PAUSE          0x13	//Pause
	VK_CAPITAL        0x14	//Caps Lock
	VK_ESCAPE         0x1B	//Esc
	VK_SPACE          0x20	//�ո�
	VK_PRIOR          0x21	//Page Up
	VK_NEXT           0x22	//Page Down
	VK_END            0x23	//End
	VK_HOME           0x24	//Home
	
	//�����
	VK_LEFT           0x25	//������� 
	VK_UP             0x26	//������� 
	VK_RIGHT          0x27	//������� 
	VK_DOWN           0x28	//������� 
	
	VK_SNAPSHOT       0x2C	//Print Screen
	VK_INSERT         0x2D	//Insert
	VK_DELETE         0x2E	//Delete
	
	//���ֺ���ĸ(0��9��A��Z)�����������ASCII��
	
	VK_LWIN           0x5B	//��Windows�ձ��(104���̲���) 
	VK_RWIN           0x5C	//��Windows�ձ��(104���̲���)
	VK_APPS           0x5D	//AppsKey(104���̲���)
	
	//С���� 
	VK_NUMPAD0        0x60	//С����0
	VK_NUMPAD1        0x61	//С����1
	VK_NUMPAD2        0x62	//С����2
	VK_NUMPAD3        0x63	//С����3
	VK_NUMPAD4        0x64	//С����4
	VK_NUMPAD5        0x65	//С����5
	VK_NUMPAD6        0x66	//С����6
	VK_NUMPAD7        0x67	//С����7
	VK_NUMPAD8        0x68	//С����8
	VK_NUMPAD9        0x69	//С����9
	VK_MULTIPLY       0x6A	//С����*
	VK_ADD            0x6B	//С����+
	VK_SEPARATOR      0x6C	//???
	VK_SUBTRACT       0x6D	//С����-
	VK_DECIMAL        0x6E	//С����.
	VK_DIVIDE         0x6F	//С����/
	
	//���ܼ�F1-F24
	VK_F1             0x70 
	VK_F2             0x71
	VK_F3             0x72
	VK_F4             0x73
	VK_F5             0x74
	VK_F6             0x75
	VK_F7             0x76
	VK_F8             0x77
	VK_F9             0x78
	VK_F10            0x79
	VK_F11            0x7A
	VK_F12            0x7B
	VK_F13            0x7C
	VK_F14            0x7D
	VK_F15            0x7E
	VK_F16            0x7F
	VK_F17            0x80
	VK_F18            0x81
	VK_F19            0x82
	VK_F20            0x83
	VK_F21            0x84
	VK_F22            0x85
	VK_F23            0x86
	VK_F24            0x87
	
	VK_NUMLOCK        0x90	//Num Lock ��
	VK_SCROLL         0x91	//Scroll Lock �� 
	
	VK_LSHIFT         0xA0	//��Shift
	VK_RSHIFT         0xA1	//��Shift
	VK_LCONTROL       0xA2	//��Ctrl
	VK_RCONTROL       0xA3	//��Ctrl
	VK_LMENU          0xA4	//��Alt
	VK_RMENU          0xA5	//��Alt
	����̷ֺ�        0xBA VK_OEM_1
	����̵Ⱥ�        0xBB VK_OEM_PLUS
	����̶���        0xBC VK_OEM_COMMA
	����̼���        0xBD VK_OEM_MINUS
	�����С����      0xBE VK_OEM_PERIOD
	�������б��      0xBF VK_OEM_2
	����̷�������    0xC0 VK_OEM_3
	�������������    0xDB VK_OEM_4
	����̷�б��      0xDC VK_OEM_5
	�������������    0xDD VK_OEM_6
	���������        0xDE VK_OEM_7
*/

#endif
