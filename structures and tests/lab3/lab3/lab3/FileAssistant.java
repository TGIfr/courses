package lab3;

import java.io.IOException;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/**
 * KPI- FPM - PZKS
 * Course: Algorithms and Data Structures (1)
 * Laboratory work 3
 * @author Olena Khomenko
 * 
 * Represents methods for reading integer values from text file
 * 
 */
public class FileAssistant {
	private String inputFile = null; 
	private int posIterator = -1;
	private List<String> tokens;
	public static final int ERROR_CODE = 404;

	public FileAssistant(String fileName) {
		setFileName(fileName);
		tokens = new ArrayList();

	}

	public FileAssistant() {
		tokens = new ArrayList();
	}

	public List<String> getTokens() {
		return tokens;
	}

	public void setFileName(String dirName, String fileName) {
		if (!checkString(fileName) || !checkString(dirName)) {
			return;
		}
		inputFile = Paths.get(dirName, fileName).toString();

	}

	public void setFileName(String fileName) {
		setFileName(System.getProperty("user.dir"), fileName);
	}

	private boolean checkString(String inputFile) {
		if (inputFile == null || isEmpty(inputFile)) {
			System.err.println("ERROR: name of file undefined");
			return false;
		}
		return true;
	}

	public boolean readFile() {

		Path path = Paths.get(inputFile);
		if (Files.exists(path) && Files.isReadable(path)) {

			try {
				List<String> contents = Files.readAllLines(path, StandardCharsets.UTF_8);
				for (String line : contents) {
					tokens.addAll(Arrays.asList(line.split("[ ]+")));
				}

			} catch (IOException e) {
				System.err.println("ERROR:read file error ");
				return false;
			}
			moveToBegin();
			if (tokens.size() != 0) {
				return true;
			}
		}
		return false;

	}

	private void moveToBegin() {
		if (tokens.size() != 0) {
			posIterator = 0;
		}
	}

	public String getNextWord() {
		String emptyString = "";
		if (tokens.size() == 0) {
			System.err.println("ERROR:File  " + Paths.get(inputFile).getFileName() + "  is empty");
			return emptyString;
		}

		if (posIterator < tokens.size()) {
			return tokens.get(posIterator++);
		} else {
			moveToBegin();
			return emptyString;
		}

	}

	public int readNextInt() {
		int errorCode = 404;
		if (tokens.size() == 0) {
			System.err.println("ERROR:File  " + Paths.get(inputFile).getFileName() + "  is empty");
			return errorCode;
		}
		String token = getNextWord();
		while (!isEmpty(token)) {
			try {
				int number = Integer.parseInt(token);
				return number;
			} catch (NumberFormatException e) {
			}
			token = getNextWord();
		}
		return errorCode;
	}

	private boolean isEmpty(String str) {
		return str.length() == 0 || str == null;
	}

}
