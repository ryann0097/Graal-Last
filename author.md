# Identificação Pessoal

Preencha os dados abaixo para identificar a autoria do trabalho.

- Nome: *<Ryan David dos Santos Silvestre>*
- Email: *<ryan.silvestre.718@ufrn.edu.br>*
- Turma: *<DIM0176 - T01>*

# Questões Finalizadas

- [X] minmax
- [X] reverse
- [X] copy
- [X] find_if
- [X] all_of
- [X] any_of
- [X] none_of
- [X] equal
- [X] unique
- [X] partition

--------------------------------------------

Comentários do autor:
    
    Professor, tive algumas dúvidas sobre as funções UNIQUE e a primeira sobrecarga da EQUAL.
    Antecipadamente, peço desculpas por qualquer incômodo que minhas muitas mensagens possam ter causado. Como falei 
    no Discord outro dia, tive uma semana muito corrida, apenas me disponibilizando algum tempo durante o final de semana
    até o dia de entrega. Como entraves nesse primeiro projeto, tive a falta de tempo hábil devido a outras atividades extracurriculares,
    outras matérias e trabalho, falta de conhecimento prévio da ferramenta "CMake", falta de conhecimento prévio da ferramenta "Git".
    Porém, fico feliz em informar que consegui contornar esses problemas e estar apresentando o presente trabalho ao senhor.
    Creio que nos compromissamos a pagar a matéria com o senhor por livre e espontânea vontade, não devendo, depois, reclamar
    do que nós mesmos escolhemos. Nossa melhor opção é dar nosso melhor e evitar ao máximo qualquer tipo de desculpas.
    
     - Sobre a EQUAL, falei com o senhor na aula de 19/03 sobre o problema, mas não consegui resolver. 
    Procurei alguns tópicos sobre aritmética de ponteiros, tentei implementações com somas e incrementos, tudo sem sucesso.
    Daí, falei com a colega de sala "Beatriz Camilo" e comparamos nossos códigos. Vi que apenas estava usando uma abordagem
    errada, mas estava no caminho certo. Aqui está minha abordagem inicial após falar com o senhor:

    template <typename Itr, typename Equal>
    bool equal (Itr first1, Itr last1, Itr first2, Equal eq){
        int Iterador = 0;
        while(first1 != last1){
            Iterador++;
        }
        Itr FullRange = (last1 - first1);
        Itr HalfRange = first2;
        for(int i = 0; i < Iterador; i++){
            HalfRange++;
        }
    return eq(FullRange, HalfRange);
    }

    Após ver como estava a função dela, percebi que eu só teria de usar uma abordagem semelhante à das outras questões, não inventar
    coisas do nada.

-----------------------------------------------

    - Sobre a UNIQUE, inicialmente utilizei a abordagem vista em sala da FILTEr, em que abordávamos a questão dos ponteiros lentos
    e rápidos. Porém, ao tentar compilar, vi que tinha alguns erros e dei uma olhada do Copilot sobre como resolver.
    template <typename Itr, typename Equal> 
    
    <!--Código Inicial-->
    Itr unique(Itr first, Itr last, Equal eq) {
    Itr pointerOne = first;
    Itr pointerTwo = first;

    while(pointerOne != last){
        for(auto it = first; it != pointerOne; it++){
        if(!(eq(*pointerOne, *it))){  
                *pointerTwo = *pointerOne;
                pointerTwo++;
                }
            }
        pointerOne++;
    }
        return pointerTwo;
    } 

    <!--Código Final-->
    template <typename Itr, typename Equal> 
    Itr unique(Itr first, Itr last, Equal eq) {
    if (first == last) return last;

    Itr pointerOne = first;
    while (++first != last) {
        if (!eq(*pointerOne, *first)) {
            *(++pointerOne) = *first;
        }
    }
    return ++pointerOne;
    }


&copy; DIMAp/UFRN 2022.
