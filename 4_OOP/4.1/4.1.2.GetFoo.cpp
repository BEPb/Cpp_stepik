// task 4.1.2.
/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 * Не нужно его расскоментировать и/или менять.
 *
 * #include <iostream>
 *
 * struct Foo {
 *     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 * protected:
 *     Foo(const char *msg) : msg(msg) { }
 * private:
 *     const char *msg;
 * };
 *
 * void foo_says(const Foo &foo) { foo.say(); }
 *
 */

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));

/* Мы создали функцию get_foo, которая принимает указатель на строку сообщения и возвращает объект типа Foo. Внутри
функции определен дочерний класс Foo1, который наследуется от родительского класса Foo. В конструкторе класса Foo1
инициализируется строка сообщения и вызывается конструктор родительского класса. Также определен метод say, который
выводит сообщение на экран. Объект класса Foo1 создается внутри функции и возвращается как объект типа Foo.
*/
Foo get_foo(const char *msg) {  // на входе указатель строки сообщения
	struct Foo1 : Foo {  // объявляем дочерний класс Foo1 который наследуются от родительского Foo
	public:  // делаем следующую часть публичной
		Foo1(const char *msg) : Foo(msg) { } // конструкторе класса Foo1 инициализируется строка сообщения и вызывается конструктор родительского класса
		void say() const { std::cout << "Foo says: " << msg << "\n"; }  // метод say, который выводит сообщение на экран
		const char* msg;  // константа указатель сообщения
	};
	Foo1 f = Foo1(msg);  // создаем копию объекта
	return f; // возвращаем полученный объект
}