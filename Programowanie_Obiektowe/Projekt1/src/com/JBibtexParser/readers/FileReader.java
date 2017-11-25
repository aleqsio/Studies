package com.JBibtexParser.readers;

import com.JBibtexParser.util.BlockProviderException;
import com.sun.deploy.util.StringUtils;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class FileReader implements IBlocksProvider{

    private static FileReader instance = null;
    private String filepath;
    private BufferedReader br;
    private String appendToNextEntry="";

    public void setFilepath(String filepath){
        this.filepath=filepath;
    }
    public static FileReader getInstance() {
        if (instance == null) {
            instance = new FileReader();
        }
        return instance;
    }

    @Override
    public void openProvider() throws BlockProviderException {

        try {
            if(filepath==null || filepath.length()==0) throw new FileNotFoundException("filepath can not be empty");
                br = new BufferedReader(new java.io.FileReader(filepath));
        } catch (FileNotFoundException e) {
            throw new BlockProviderException("file does not exist: " + e.getMessage());
        }
    }

    public String nextEntry() throws BlockProviderException {
        StringBuilder sb = new StringBuilder();
        sb.append(appendToNextEntry);
        appendToNextEntry="";

            int bracketCounter=0;
            boolean currentEntry=true;
        try {
            while (br.ready() && currentEntry) {

                char r = (char) br.read();
                if (r == '{') {
                    bracketCounter++;
                }
                if (r == '}') {
                    bracketCounter--;
                    if(bracketCounter==0)
                    {
                        currentEntry=false;
                    }
                }
                if (r == '@') {
                    currentEntry=false;
                    appendToNextEntry="@";
                }else {
                    sb.append(r);
                }
            }
        } catch (IOException e) {
            throw new BlockProviderException("Failed to open File " + e.getMessage());
        }

        return sb.toString();
    }

    public boolean hasNextEntry() throws BlockProviderException {
        try {
            return br.ready();
        } catch (IOException e) {
            throw new BlockProviderException("Failed to read some entries from file" + e.getMessage());
        }
    }

    @Override
    public void closeProvider() {
        try {
            br.close();
        } catch (IOException e) {
            //assume file to be closed
        }
    }

}