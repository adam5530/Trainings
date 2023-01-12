#include <iostream>

using namespace std;

class Paragraph
{
public:
    explicit Paragraph(std::string const& init)
            :m_para(init)
        {}
    std::string const&  to_str() const
    {
        return m_para;
    }
    bool operator==(Paragraph const& rhs) const
    {
        return m_para == rhs.m_para;
    }
    bool operator!=(Paragraph const& rhs) const
    {
        // Define != operator in terms of the == operator
        return !(this->operator==(rhs));
    }
    bool operator<(Paragraph const& rhs) const
    {
        return  m_para < rhs.m_para;
    }
private:
    friend std::ostream & operator<<(std::ostream &os, const Paragraph& p);
    std::string     m_para;
};

std::ostream & operator<<(std::ostream &os, const Paragraph& p)
{
    return os << p.to_str();
}

int main(int argc, char **argv)
{
    Paragraph p("first");
    Paragraph s(p);

    cout << p << endl << (p == s) << endl;

    Paragraph t("second");
    cout << p << endl << (p == t) << endl;
    return 0;
}