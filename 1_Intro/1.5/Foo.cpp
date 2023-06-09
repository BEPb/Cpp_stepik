#ifndef FOO_HPP
#define FOO_HPP
void foo();
#endif

/*
Любой заголовочный файл C/C++ должен иметь следующую структуру:
#ifndef ИМЯ_ЗАГОЛОВОЧНОГО_ФАЙЛА
#define ИМЯ_ЗАГОЛОВОЧНОГО_ФАЙЛА
// здесь помещается остальной текст заголовочного файла
#endif // ИМЯ_ЗАГОЛОВОЧНОГО_ФАЙЛА:

Директивы ifndef-define-endif, которые обрамляют любой грамотно оформленный заголовочный файл, являются трюком
препроцессора: они обеспечивают то, что любой заголовочный файл будет включён в любой исходный файл не более одного раза.

Каждому заголовочному файлу «вручную» ставится в соответствие некоторый «символ», обычно связанный с именем этого
файла, чтобы обеспечить уникальность. В первой строке проверяется, был ли уже определён этот символ ранее, если да, то
весь остальной текст игнорируется. Если нет, то этот символ определяется, а затем вставляется и весь остальной текст
заголовочного файла. Последняя строка (
endif
) просто означает закрытие такого «условного оператора».
*/