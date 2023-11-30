
#pragma once

#include <string>


class Brain {
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    Brain& operator=(const Brain& other);

    void setIdea(int idx, const std::string& idea);
    void showIdeas() const;

private:
    std::string ideas[100];
};

