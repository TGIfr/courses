public class ConvertationException extends Exception {
    public ConvertationException(Class from, Class to) {
        super(String.format("Cannot convert object of type %s to %s", from.getName(), to.getName()));
    }
}
