#pragma once

#include <string>
#include <vector>

#include <webhook/Colour.h>
#include <webhook/Footer.h>
#include <webhook/Thumbnail.h>
#include <webhook/Image.h>
#include <webhook/Author.h>
#include <webhook/Field.h>

class EmbedObject
{
public:
	std::string getTitle() { return title; }
	std::string getDescription() { return description; }
	std::string getUrl() { return url; }
	Colour getColour() { return colour; }

	Footer getFooter() { return footer; }
	Thumbnail getThumbnail() { return thumbnail; }
	Image getImage() { return image; }
	Author getAuthor() { return author; }
	std::vector<Field> getFields() { return fields; }

	EmbedObject() {}

	EmbedObject& setTitle(std::string title)
	{
		this->title = title;
		return *this;
	}

	EmbedObject& setDescription(std::string description)
	{
		this->description = description;
		return *this;
	}

	EmbedObject& setUrl(std::string url)
	{
		this->url = url;
		return *this;
	}

	EmbedObject& setColour(Colour colour)
	{
		this->colour = colour;
		return *this;
	}

	EmbedObject& setFooter(std::string text, std::string icon)
	{
		this->footer = Footer{ text, icon };
		return *this;
	}

	EmbedObject& setThumbnail(std::string url)
	{
		this->thumbnail = Thumbnail{ url };
		return *this;
	}

	EmbedObject& setImage(std::string url)
	{
		this->image = Image{ url };
		return *this;
	}

	EmbedObject& setAuthor(std::string name, std::string url, std::string icon)
	{
		this->author = Author{ name, url, icon };
		return *this;
	}

	EmbedObject& addField(std::string name, std::string value, bool inline_field)
	{
		this->fields.emplace_back(Field{ name, value, inline_field });
		return *this;
	}

private:
	std::string title;
	std::string description;
	std::string url;
	Colour colour = Colour::BLACK;

	Footer footer;
	Thumbnail thumbnail;
	Image image;
	Author author;
	std::vector<Field> fields;
};