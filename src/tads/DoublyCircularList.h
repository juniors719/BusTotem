#ifndef DOUBLYCIRCULARLIST_H
#define DOUBLYCIRCULARLIST_H

/**
 * @brief Classe que implementa a lógica de uma lista duplamente encadeada circular
 *
 * @tparam T
 */
template <typename T>
class DoublyCircularList {
    /**
     * @brief Classe que representa um nó da lista circular
     *
     */
    class Node {
       public:
        T data;      // dado armazenado no nó
        Node *next;  // ponteiro para o próximo elemento da lista
        Node *prev;  // ponteiro para o elemento anterior da lista

        Node(T data) : data(data), next(nullptr), prev(nullptr) {}  // construtor
        ~Node() { delete next; }                                    // destrutor
    };
    class Iterator {
    };

   private:
    Node *m_head;     // ponteiro para o nó sentinela
    unsigned m_size;  // tamanho da lista
   public:
    /**
     * @brief Construtor da classe DoublyCircularList
     * Cria um nó sentinela e faz com que ele aponte para si mesmo
     *
     */
    DoublyCircularList() : m_head(new Node(T())), m_size(0) {
        m_head->next = m_head;
        m_head->prev = m_head;
    }

    ~DoublyCircularList() { clear(); }

    /**
     * @brief Método que retorna se a lista está vazia
     *
     * @return true
     * @return false
     */
    bool empty() const { return m_size == 0; }

    /**
     * @brief Método que retorna o tamanho da lista
     *
     * @return unsigned
     */
    unsigned size() const { return m_size; }

    /**
     * @brief Método que retorna o primeiro elemento da lista
     *
     * @return T&
     */
    T &front() const { return m_head->next->data; }

    /**
     * @brief Método que retorna o último elemento da lista
     *
     * @return T&
     */
    T &back() const { return m_head->prev->data; }

    /**
     * @brief Método que insere um elemento no início da lista
     *
     * @param data Dado a ser inserido
     */
    void push_front(const T &data) {
        Node *newNode = new Node(data);  // cria um novo nó com o dado
        newNode->next = m_head->next;    // o próximo elemento do novo nó é o primeiro elemento da lista
        newNode->prev = m_head;          // o elemento anterior do novo nó é o nó sentinela
        m_head->next->prev = newNode;    // o elemento anterior do primeiro elemento da lista é o novo nó
        m_head->next = newNode;          // o primeiro elemento da lista é o novo nó
        m_size++;                        // incrementa o tamanho da lista
    }

    /**
     * @brief Método que insere um elemento no final da lista
     *
     * @param data Dado a ser inserido
     */
    void push_back(const T &data) {
        Node *newNode = new Node(data);  // cria um novo nó com o dado
        newNode->next = m_head;          // o próximo elemento do novo nó é o nó sentinela
        newNode->prev = m_head->prev;    // o elemento anterior do novo nó é o último elemento da lista
        m_head->prev->next = newNode;    // o próximo elemento do último elemento da lista é o novo nó
        m_head->prev = newNode;          // o último elemento da lista é o novo nó
        m_size++;                        // incrementa o tamanho da lista
    }
};

#endif  // DOUBLYCIRCULARLIST_H