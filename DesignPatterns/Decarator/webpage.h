#include <memory>
#include <iostream>
#include <string>

struct WebPage
{
    virtual void display() const = 0;
    virtual ~WebPage() = default;
};

struct BasicWebPage : WebPage
{
    std::string html;
    void display() const override
    {
        std::cout << "Basic WEB page html: " << html << '\n';
    }
};

struct WebPageDecorator : WebPage
{
    WebPageDecorator(std::unique_ptr<WebPage> webPage) : _webPage(std::move(webPage))
    {
    }
    void display() const override
    {
        _webPage->display();
    }
private:
    std::unique_ptr<WebPage> _webPage;
};

struct AuthenticatedWebPage : WebPageDecorator
{
    AuthenticatedWebPage(std::unique_ptr<WebPage> webPage) :
        WebPageDecorator(std::move(webPage))
    {}

    void authenticateUser()const
    {
        std::cout << "authentification done" << '\n';
    }
    void display() const override
    {
        authenticateUser();
        WebPageDecorator::display();
    }
};

struct AuthorizedWebPage : WebPageDecorator
{
    AuthorizedWebPage(std::unique_ptr<WebPage> webPage) :
        WebPageDecorator(std::move(webPage))
    {}

    void authorizedUser() const
    {
        std::cout << "authorized done" << '\n';
    }
    void display() const override
    {
        authorizedUser();
        WebPageDecorator::display();
    }
};