package kotlin;

import java.util.ArrayList;

public class Ts {

    public static void main(String[] args) {
        Test();
    }

    private static void Test() {
        User user = new User("123", 12);
        ArrayList<User> users = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            user.setName("张三" + i);
            users.add(user);
            System.out.println(users.toString());
        }
        System.out.println(users.toString());

        users.clear();
        users.add(new User("0-", 0));
        users.add(new User("1-", 1));
        users.add(new User("2-", 2));
        users.add(new User("3-", 3));

        HomeMenu homeMenu = new HomeMenu("123", "123");
        ArrayList<HomeMenu> menus = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            homeMenu.setName(users.get(i).getName() + i);
            menus.add(homeMenu);
            System.out.println(menus.toString());
        }
        for (int i = 0; i < menus.size(); i++) {
            System.out.println(menus.get(i).getName());
        }
    }
}
