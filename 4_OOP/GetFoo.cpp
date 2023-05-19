Foo get_foo(const char *msg) {
	struct Foo1 : Foo {
	public:
		Foo1(const char *msg) : Foo(msg) { }
		void say() const { std::cout << "Foo says: " << msg << "\n"; }
		const char* msg;
	};
	Foo1 f = Foo1(msg);
	return f;
}