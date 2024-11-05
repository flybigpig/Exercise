package src;

public class HomeMenu {
    String name;
    String title;

    public HomeMenu(String name, String title) {
        this.name = name;
        this.title = title;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    @Override
    public String toString() {
        return "HomeMenu{" +
                "name='" + name + '\'' +
                ", title='" + title + '\'' +
                '}';
    }
}
