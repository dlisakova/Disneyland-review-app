#include "settings.h"
#include <QObject>
settings::settings()
{

}

Q_GLOBAL_STATIC(settings, global_inst)
settings *settings::instanse()
{
    return global_inst();
}

int settings::getmin_rating() const
{
    return _min_rating;
}

void settings::setmin_rating(int min_rating)
{
    _min_rating = min_rating;
}

int settings::getmax_rating() const
{
    return _max_rating;
}

void settings::setmax_rating(int max_rating)
{
    _max_rating = max_rating;
}
