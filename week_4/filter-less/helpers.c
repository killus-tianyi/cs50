#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE grayscale = (BYTE)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtRed = grayscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = (int)round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = (int)round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = (int)round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = (sepiaRed > 255)? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255)? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255)? 255 : sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            RGBTRIPLE tmpt = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmpt;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a tempture 2-D array to store the pixel information
    RGBTRIPLE tmpts[height][width];

    for (int i = 0; i <height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate the average for every pixel
            int red = 0, blue = 0, green = 0, count = 0;
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    if (i + m > -1 && i + m < height && j + n > -1 && j + n < width)
                    {
                        red += image[i + m][j + n].rgbtRed;
                        blue += image[i + m][j + n].rgbtBlue;
                        green += image[i + m][j + n].rgbtGreen;
                        count++;
                    }
                }
            }

            tmpts[i][j].rgbtRed = (BYTE)round(red / (float)count);
            tmpts[i][j].rgbtBlue = (BYTE)round(blue / (float)count);
            tmpts[i][j].rgbtGreen = (BYTE)round(green / (float)count);
        }
    }

    //assign all the value of tmpt into image
    for (int i = 0; i <height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmpts[i][j];
        }
    }
    return;
}
