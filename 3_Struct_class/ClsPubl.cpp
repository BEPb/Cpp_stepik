 struct ClsPubl
 {
	 ClsPubl(char _c, double _d, int _i);
 public:
	 char c;
	 double d;
	 int i;
 };

 char& get_c(Cls& cls) {
	 void* voidptr = static_cast<void*>(&cls); 
	 struct ClsPubl* p = static_cast<ClsPubl*>(voidptr); 
	 return p->c; 
 }

 double& get_d(Cls& cls)
 {
	 void* voidptr = static_cast<void*>(&cls);
	 struct ClsPubl* p = static_cast<ClsPubl*>(voidptr);
	 return p->d;
 }


 int& get_i(Cls& cls)
 {
	 void* voidptr = static_cast<void*>(&cls);
	 struct ClsPubl* p = static_cast<ClsPubl*>(voidptr);
	 return p->i;
 }