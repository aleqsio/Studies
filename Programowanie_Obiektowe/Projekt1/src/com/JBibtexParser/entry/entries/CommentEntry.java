package com.JBibtexParser.entry.entries;

import com.JBibtexParser.entry.IEntry;

public class CommentEntry implements IEntry {

	private String commentText;

	public String getCommentText() {
		return commentText;
	}

	public void setCommentText(String commentText) {
		this.commentText = commentText;
	}
}