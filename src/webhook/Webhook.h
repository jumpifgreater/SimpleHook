#pragma once
#include <cpr/cpr.h>
#include <webhook/JsonObject.h>
#include <webhook/EmbedObject.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "Secur32.lib")

class Webhook
{
public:
    Webhook(std::string url)
    {
        if (!url.starts_with("https://discord.com/api/webhooks/") && !url.starts_with("https://canary.discord.com/api/webhooks/"))
        {
            std::printf("invalid webhook\n");
            Sleep(2000);
            exit(1);
        }

        this->url = url;
    }

    Webhook& setContent(std::string content)
    {
        this->content = content;
        return *this;
    }

    Webhook& setUsername(std::string username)
    {
        this->username = username;
        return *this;
    }

    Webhook& setAvatarUrl(std::string avatarUrl)
    {
        this->avatarUrl = avatarUrl;
        return *this;
    }

    Webhook& addEmbed(EmbedObject embed)
    {
        this->embeds.push_back(embed);
        return *this;
    }

    void execute()
    {
        if (content.empty() && embeds.empty())
        {
            std::printf("set content or add at least one EmbedObject\n");
            Sleep(2000);
            exit(1);
        }

        JSONObject json;
        json.put("content", content);
        json.put("username", username);
        json.put("avatar_url", avatarUrl);

        if (!embeds.empty())
        {
            std::vector<JSONObject> embedObjects;

            for (auto& embed : embeds)
            {
                JSONObject jsonEmbed;

                jsonEmbed.put("title", embed.getTitle());
                jsonEmbed.put("description", embed.getDescription());
                jsonEmbed.put("url", embed.getUrl());

                Colour colour = embed.getColour();
                int rgb = (colour.r << 16) | (colour.g << 8) | colour.b;
                jsonEmbed.put("color", rgb);

                Footer footer = embed.getFooter();
                JSONObject jsonFooter;
                jsonFooter.put("text", footer.text);
                jsonFooter.put("icon_url", footer.icon_url);
                jsonEmbed.put("footer", jsonFooter);

                Thumbnail thumbnail = embed.getThumbnail();
                JSONObject jsonThumbnail;
                jsonThumbnail.put("url", thumbnail.url);
                jsonEmbed.put("thumbnail", jsonThumbnail);

                Image image = embed.getImage();
                JSONObject jsonImage;
                jsonImage.put("url", image.url);
                jsonEmbed.put("image", jsonImage);

                Author author = embed.getAuthor();
                JSONObject jsonAuthor;
                jsonAuthor.put("name", author.name);
                jsonAuthor.put("url", author.url);
                jsonAuthor.put("icon_url", author.icon_url);
                jsonEmbed.put("author", jsonAuthor);

                std::vector<JSONObject> jsonFields;

                for (auto& field : embed.getFields())
                {
                    JSONObject jsonField;
                    jsonField.put("name", field.name);
                    jsonField.put("value", field.value);
                    jsonField.put("inline", field.b_inline);
                    jsonFields.push_back(jsonField);
                }

                json.put("fields", jsonFields);
                embedObjects.push_back(jsonEmbed);
            }

            json.put("embeds", embedObjects);
        }

        cpr::Response r = cpr::Post(
            cpr::Url{ url },
            cpr::Header{
                {"Content-Type", "application/json"},
                {"User-Agent", "lolz"}
            },
            cpr::Body{ json.toString() }
        );
    }

    private:
        std::string url;
        std::string content;
        std::string username;
        std::string avatarUrl;
        std::vector<EmbedObject> embeds;
};