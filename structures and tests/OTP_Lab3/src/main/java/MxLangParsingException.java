public class MxLangParsingException extends Exception {
    public MxLangParsingException(Exception cause) {
        super(cause);
    }

    @Override
    public String toString() {
        return String.format("ERROR. %s", super.getCause().getMessage());
    }
}
