<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
  <h2>Book Store Collection</h2>
  <table>
    <tr bgcolor="grey">
      <th>Title</th>
      <th>Author</th>
      <th>ISBN</th>
      <th>Publisher</th>
      <th>Edition</th>
      <th>Price</th>
    </tr>
    <xsl:for-each select="bookstore/book">
    <tr>
      <td bgcolor="yellow"><xsl:value-of select="title"/></td>
      <td style="background-color:green">
        <b>
          <xsl:value-of select="author"/>
        </b>
      </td>
      <td bgcolor="red"><xsl:value-of select="ISBN"/></td>
     <td bgcolor="violet"><xsl:value-of select="Publisher"/></td>
     <td><xsl:value-of select="Edition"/></td>
    <td><xsl:value-of select="price"/></td>
    </tr>
    </xsl:for-each>
  </table>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet> 