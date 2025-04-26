//
// Created by cicero on 23/04/25.
//

#ifndef IEXCECAO_H
#define IEXCECAO_H

#include <exception>
#include <string>


class IExcecao : public std::exception {

public:
    IExcecao() = default;
    explicit IExcecao(const std::string&);

    ~IExcecao() noexcept override = default;

    const char * what() const noexcept override;

protected:

    std::string mensagem;
};



#endif //IEXCECAO_H
