#ifndef SETTINGS_H
#define SETTINGS_H


class settings
{
public:
    settings();
    static settings *instanse();
    int getmin_rating() const;
    void setmin_rating(int min_rating);
    int getmax_rating() const;
    void setmax_rating(int max_rating);
private:
    int _min_rating;
    int _max_rating;
};

#endif // SETTINGS_H

