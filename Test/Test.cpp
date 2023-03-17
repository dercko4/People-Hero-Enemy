#include <needincludes.h>
#include "B_people_with_crit.h"
int main()
{
    setlocale(LC_ALL, "Rus");
    srand((unsigned int)time(0));
    Hero good(100, 20, 11, 25, "Герой", 1.6, 40);
    Enemy bad(120, 20, 13, 25, "Враг", 1.9, 25);
    good.info();
    bad.info();
    cout << endl;
    for (int i = 1;; i++)
    {
        cout << "Раунд:" << i << endl;
        good.set_damage();
        bad.set_hp(good.get_damage(), good.get_crit(), good.get_chance_crit());
        if (bad.get_hp() == 0)
        {
            cout << "Раунд " << i << " окончен" << endl << endl;
            break;
        }
        cout << endl;
        bad.set_damage();
        good.set_hp(bad.get_damage(), bad.get_crit(), bad.get_chance_crit());
        if (good.get_hp() == 0)
        {
            cout << "Раунд " << i << " окончен" << endl << endl;
            break;
        }
        cout << "Раунд " << i << " окончен" << endl << endl;
    }
    return 0;
}