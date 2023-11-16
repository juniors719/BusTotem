#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>

/**
 * @brief Classe que implementa uma lista encadeada simples
 *
 */
template <typename T>
class ForwardList {
    class Node {
       public:
        T data;      // dado armazenado no nó
        Node* next;  // ponteiro para o próximo elemento da lista

        Node(T data, Node* next) : data(data), next(next) {}  // construtor
        ~Node() { delete next; }                              // destrutor
    };
    class Iterator {
       private:
        Node* m_ptr;

       public:
        Iterator(Node* ptr) : m_ptr(ptr) {}

        Iterator& operator++() {
            m_ptr = m_ptr->next;
            return *this;
        }

        T& operator*() { return m_ptr->data; }

        bool operator!=(const Iterator& other) { return m_ptr != other.m_ptr; }
    };

   private:
    Node* m_head{};     // ponteiro para o nó sentinela
    Node* m_tail{};     // ponteiro para o último elemento da lista
    unsigned m_size{};  // tamanho da lista

   public:
    /**
     * @brief Construct a new Forward List object
     *
     */
    ForwardList() { m_tail = m_head = new Node(0, nullptr); }

    /**
     * @brief Construct a new Forward List object
     *
     * @param other
     */
    ForwardList(const ForwardList& other) {
        m_tail = m_head = nullptr;  // Inicializa m_head e m_tail como nullptr
        Node* aux = other.m_head->next;
        while (aux != nullptr) {
            push_back(aux->data);  // Usa push_back para inserir elementos na nova lista
            aux = aux->next;
        }
        m_size = other.m_size;
    }
    /**
     * @brief Função que retorna o tamanho da lista
     *
     * @return unsigned int
     */
    unsigned int size() const { return m_size; }

    /**
     * @brief função que insere no início da lista
     *
     * @param data valor a ser inserido
     */
    void push_front(const int& data) {
        Node* new_node = new Node(data, m_head->next);
        m_head->next = new_node;
        if (m_size == 0) m_tail = new_node;
        m_size++;
    }

    /**
     * @brief função que insere no final da lista
     *
     * @param data
     */
    void push_back(const T& data) {
        Node* new_node = new Node(data, nullptr);
        m_tail->next = new_node;
        m_tail = new_node;
        m_size++;
    }

    /**
     * @brief Função que retorna uma referência para o primeiro elemento da lista
     *
     * @return T&
     */
    T& front() const { return m_head->next->data; }

    /**
     * @brief Função que retorna uma referência para o último elemento da lista
     *
     * @return T&
     */
    T& back() const { return m_tail->data; }

    /**
     * @brief função que remove o primeiro elemento da lista
     *
     */
    void pop_front() {
        if (m_size == 0) return;
        Node* aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
        m_size--;
    }

    bool empty() const { return m_size == 0; }

    /**
     * @brief Função que remove todos os elementos da lista
     *
     */
    void clear() {
        while (m_head->next != nullptr) {
            Node* aux2 = m_head->next;
            m_head->next = aux2->next;
            delete aux2;
        }
        m_tail = m_head;
        m_size = 0;
    }

    /**
     * @brief Destroy the Forward List object
     *
     */
    ~ForwardList() {
        delete m_head;
    }

    /**
     * @brief Função que retorna um iterador para o primeiro elemento da lista
     *
     * @return iterator_list iterador para o primeiro elemento da lista
     */
    Iterator begin() { return Iterator(m_head->next); }

    /**
     * @brief Função que retorna um iterador para o elemento após o último
     *
     * @return iterator_list iterador para o elemento após o último
     */
    Iterator end() { return Iterator(nullptr); }

    /**
     * @brief Função que retorna um iterador para o nó sentinela
     *
     * @return iterator_list iterador para o nó sentinela
     */
    Iterator before_begin() { return Iterator(m_head); }

    // FUNÇÃO O(N²) -> NÃO FAÇA ISSO
    /**
     * @brief Sobrecarga do operador de indexação.
     * Recebe um índice e retorna uma referência para
     * o dado naquela posição.
     * Essa função não checa se o índice é válido.
     * Ela confia no usuário para passar um índice válido.
     *
     * @param index índice do elemento a ser retornado
     * @return int&
     */
    // int& operator[](unsigned int index) {
    //     Node* aux = m_head->next;
    //     for (unsigned int i = 0; i < index; i++) {
    //         aux = aux->next;
    //     }
    //     return aux->data;
    // }
};

#endif  // FORWARD_LIST_H